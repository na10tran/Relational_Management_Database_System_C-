#ifndef MMAP_H
#define MMAP_H
#include "../Final_Project_Submission/includes_folder/MPair.h"
#include "../Final_Project_Submission/includes_folder/bplustree.h"
#include <vector>

template <typename K, typename V>
class MMap
{
public:
    typedef BPlusTree<MPair<K, V> > map_base;
    class Iterator {
    public:
        friend class MMap;
        Iterator(typename map_base::Iterator it = typename map_base::Iterator()) {
            _it = it;
        }
        MMap<K, V>::Iterator operator ++(int unused) {
            return MMap<K, V>::Iterator(++_it);
        }
        MMap<K, V>::Iterator operator ++() {
            return MMap<K, V>::Iterator(_it++);
        }
        MPair<K, V> operator *() {
            return *_it;
        }

        friend bool operator ==(const MMap<K, V>::Iterator& lhs,
            const MMap<K, V>::Iterator& rhs) {
            return lhs._it == rhs._it;
        }

        friend bool operator !=(const MMap<K, V>::Iterator& lhs,
            const MMap<K, V>::Iterator& rhs) {
            return !(lhs == rhs);
        }

        friend ostream& operator <<(ostream& outs, const MMap<K, V>::Iterator& iter) {
            outs << iter._it;
            return outs;
        }

    private:
        typename map_base::Iterator _it;
    };

    MMap();

    //  Iterators
    MMap<K, V>::Iterator begin();
    MMap<K, V>::Iterator end();
    MMap<K, V>::Iterator lower_bound(const K& key);
    MMap<K, V>::Iterator upper_bound(const K& key);

    //  Capacity
    int size() const;
    bool empty() const;

    //  Element Access
    const vector<V>& operator[](const K& key) const;
    vector<V>& operator[](const K& key);

    //  Modifiers
    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();

    //  Operations:
    bool contains(const K& key);
    vector<V>& get(const K& key);

    MMap<K, V>::Iterator find(const K& key);
    int count(const K& key);
    // I have not writtent hese yet, but we will need them:
    //    int count(const K& key);
    //    lower_bound
    //    upper_bound
    //    equal_range:



    bool is_valid();

    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me) {
        outs << print_me.mmap << endl;
        return outs;
    }

private:
    BPlusTree<MPair<K, V> > mmap;
};


template<typename K, typename V>
MMap<K, V>::MMap() {}

template<typename K, typename V>
typename MMap<K, V>::Iterator MMap<K, V>::begin()
{
    return MMap<K, V>::Iterator(mmap.begin());
            //Returs an Iterator to the start of the MMap Keys.
}

template<typename K, typename V>
typename MMap<K, V>::Iterator MMap<K, V>::end()
{
    return MMap<K, V>::Iterator(mmap.end());
            //Returns an Iterator to the end of the MMap keys.
}
template<typename K, typename V>
typename MMap<K, V>::Iterator MMap<K, V>::lower_bound(const K& key)
{
    return MMap<K, V>::Iterator(mmap.lower_bound(key));
            //Returns an Iterator lowerbound of the key.
}
template<typename K, typename V>
typename MMap<K, V>::Iterator MMap<K, V>::upper_bound(const K& key)
{
    return MMap<K, V>::Iterator(mmap.upper_bound(key));
            //Returns an Iterator upperbound of the key.
}

template<typename K, typename V>
bool MMap<K, V>::contains(const K& key)
{
    return mmap.contains(MPair<K, V>(key));
            //Returns whether the key is contained in the MMap.
}

template<typename K, typename V>
vector<V>& MMap<K, V>::get(const K& key)
{
    return mmap.get(MPair<K, V>(key)).value_list;
            //returns the vector at the corresponding key. Can be changed.
}



template<typename K, typename V>
typename MMap<K, V>::Iterator MMap<K, V>::find(const K& key)
{
    return MMap<K, V>::Iterator(mmap.find(MPair<K, V>(key)));
            //Returns an Iterator to the key in MMap.
}

template<typename K, typename V>
int MMap<K, V>::count(const K& key)
{
    return this[key].size();
            //Returns the number of elements stored at a key.
}

template<typename K, typename V>
bool MMap<K, V>::is_valid()
{
    return mmap.is_valid();
            //Returns whether the MMap is valid.
}

template<typename K, typename V>
int MMap<K, V>::size() const
{
    return mmap.size();
            //Returns the size
}

template<typename K, typename V>
bool MMap<K, V>::empty() const
{
    return mmap.size() == 0;
            //Returns whther the MMap is empty of not
}

template<typename K, typename V>
const vector<V>& MMap<K, V>::operator[](const K& key) const
{
    return this[key];
            //Returns the value at the key ptr. can be used in const functions
}

template<typename K, typename V>
vector<V>& MMap<K, V>::operator[](const K& key)
{
    return get(key);
            //Returns the value list at key ptr.
}

template<typename K, typename V>
void MMap<K, V>::insert(const K& k, const V& v)
{
    mmap.insert(MPair<K, V>(k, v));
            //Inserts a value into the MMap
}

template<typename K, typename V>
void MMap<K, V>::erase(const K& key)
{
    mmap.remove(key);
            //Removes a value from the MMap.
}

template<typename K, typename V>
void MMap<K, V>::clear()
{
    mmap.clear_tree();
            //Clears the MMap.
}
#endif // MMAP_H
