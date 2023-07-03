#ifndef MPAIR_H
#define MPAIR_H
#include "../../Multimap_Final_Presentation/includes/BTree_Util_Functions.h"
#include <vector>
using namespace std;

template <typename K, typename V>
struct MPair {
    K key;
    vector<V> value_list;

    //--------------------------------------------------------------------------------
    /*      MPair CTORs:
     *  must have these CTORs:
     *  - default CTOR / CTOR with a key and no value: this will create an empty vector
     *  - CTOR with a key AND a value: pushes the value into the value_list
     *  _ CTOR with a key and a vector of values (to replace value_list)
     */
     //--------------------------------------------------------------------------------
    MPair(const K& k = K());
    MPair(const K& k, const V& v);
    MPair(const K& k, const vector<V>& vlist);
    //--------------------------------------------------------------------------------

    //You'll need to overlod << for your vector:
    friend ostream& operator <<(ostream& outs, const MPair<K, V>& print_me);

            //All conditions for comparison are checked in order to store
            //items into a Map: 

    friend bool operator ==(const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        return lhs.key == rhs.key;
    }
    friend bool operator !=(const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        return lhs.key != rhs.key;
    }
    friend bool operator < (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        return lhs.key < rhs.key;
    }
    friend bool operator <= (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        return !(lhs > rhs);
    }
    friend bool operator >= (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        return !(lhs < rhs);
    }
    friend bool operator > (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        return lhs.key > rhs.key;
    }
    friend MPair<K, V> operator + (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        MPair<K, V> temp = lhs;
                //To add two MMaps together, we just combine their vectors.

        for (int i = 0; i < rhs.value_list.size(); i++)
            temp.value_list.push_back(rhs[i]);
                //Individual values from rhs are pushed into lhs.

        return temp;

    }

    friend ostream& operator <<(ostream& outs, const MPair<K, V>& print_me) {

        outs << " " << print_me.key << ", " << print_me.value_list;
        return outs;

    }
};

#endif // !MPAIR_H

//Constructors

template<typename K, typename V>
MPair<K, V>::MPair(const K& k) : key(k) { }

template<typename K, typename V>
MPair<K, V>::MPair(const K& k, const V& v) : key(k) {
    value_list += v;
}

template<typename K, typename V>
MPair<K, V>::MPair(const K& k, const vector<V>& vlist) : key(k) {
    value_list = vlist;
}
