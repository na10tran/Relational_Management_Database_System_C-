#ifndef MAP_H
#define MAP_H
#include "BPlusTree.h"
#include "Pair.h"
#include <iostream>
using namespace std;

template <typename K, typename V>
class Map
{
public:
    typedef BPlusTree<Pair<K, V> > map_base;
    class Iterator {
    public:
        friend class Map;
        Iterator(typename map_base::Iterator it = map_base::Iterator()) {
            _it = it;
        }
        Map<K, V>::Iterator operator ++(int unused) {
            return Map<K, V>::Iterator(++_it);
        }
        Map<K, V>::Iterator operator ++() {
            return Map<K, V>::Iterator(_it++);
        }
        Pair<K, V> operator *() {
            return *_it;
        }

        friend bool operator ==(const Map<K, V>::Iterator& lhs, const Map<K, V>::Iterator& rhs) {
            return lhs._it == rhs._it;
        }
        friend bool operator !=(const Map<K, V>::Iterator& lhs, const Map<K, V>::Iterator& rhs) {
            return !(lhs == rhs);
        }
        friend ostream& operator <<(ostream& outs, const Iterator& iter) {
            outs << iter._it;
            return outs;
        }
    private:
        typename map_base::Iterator _it;

    };

    Map();
    //  Iterators
    Map<K, V>::Iterator begin();
    Map<K, V>::Iterator end();

    //  Capacity
    int size() const;
    bool empty() const;

    //  Element Access
    V& operator[](const K& key);
    V& at(const K& key);
    const V& at(const K& key) const;


    //  Modifiers
    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();
    V get(const K& key);

    //  Operations:
    Map<K, V>::Iterator find(const K& key);
    bool contains(const Pair<K, V>& target);

    // I have not writtent hese yet, but we will need them:
    //    int count(const K& key);
    //    lower_bound
    //    upper_bound
    //    equal_range:

    bool is_valid() { return map.is_valid(); }

    friend ostream& operator<<(ostream& outs, const Map<K, V>& print_me) {
        outs << print_me.map << endl;
        return outs;
    }
private:
    int key_count;
    BPlusTree<Pair<K, V> > map;
};


template<typename K, typename V>
Map<K, V>::Map() : key_count(0) {}

template<typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::begin()
{
    return Iterator(map.begin());
            //Returns an iterator to the front of the Map _keys.
}

template<typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::end()
{
    return Map<K, V>::Iterator(map.end());
            //Returns an iterator to the end of the Map (nullptr).
}

template<typename K, typename V>
int Map<K, V>::size() const
{
    return map.size();
            //Returns number of keys in the Map.
}

template<typename K, typename V>
bool Map<K, V>::empty() const
{
    return map.size() == 0;
            //Returns whether the Map is Empty.
}

template<typename K, typename V>
V& Map<K, V>::operator[](const K& key)
{
    return at(key);
            //Returns the Corresponding value of a key in the Map.
            //Uses bracket format: M[3];
}

template<typename K, typename V>
V& Map<K, V>::at(const K& key)
{
    return map.get(Pair<K, V>(key)).value;
            //Returns the Corresponding value of a key in the Map.
}

template<typename K, typename V>
const V& Map<K, V>::at(const K& key) const
{
    return at(key);
            //Same as at() above, but can be used in const function calls.
}

template<typename K, typename V>
void Map<K, V>::insert(const K& k, const V& v)
{
    map.insert(Pair<K, V>(k, v));
            //Inserts Pair into a Map.
}

template<typename K, typename V>
void Map<K, V>::erase(const K& key)
{
    map.remove(Pair<K, V>(key));
            //Removes a Pair from a Map.
}

template<typename K, typename V>
void Map<K, V>::clear()
{
    key_count = 0;
    map.clear_tree();
            //Clears the Map.
}

template<typename K, typename V>
V Map<K, V>::get(const K& key)
{
    return map.get(Pair<K, V>(key)).value;
            //Returns the value at the key. Inserts it into the Map if DNE.
}

template<typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::find(const K& key)
{
    return Map<K, V>::Iterator(map.find(Pair<K, V>(key)));
            //Returns an Iterator to the key in the 
            //Map; Iter(nullptr) otherwise
}

template<typename K, typename V>
bool Map<K, V>::contains(const Pair<K, V>& target)
{
    return map.contains(target);
            //Returns whether the Map contains the target value.
}

#endif // !MAP_H
