#include <iostream>
#include <string>
#include <list>

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class key_type>
class hash
{
private:
    Node<key_type> *array;
    int iter_size;
    int size;
    int hash_table(key_type &key)
    {
        return key % 10;
    }
    void insert_node(Node<key_type> *&hashing, key_type &key)
    {
        Node<key_type> *new_node = new Node<key_type>;
        new_node->data = key;
        new_node->next = hashing;
        hashing = new_node;
    }

public:
    hash(int s = 15)
    {
        size = 15;
        array = new Node<key_type>[s];
        for (int i = 0; i < s; i++)
        {
            array[i].next = NULL;
        }
    }

    void insert(key_type key)
    {
        int idx = hash_table(key);
        insert_node(array[idx].next, key);
    }
    void display()
    {
        for (int i = 0; i < 15; i++)
        {
            std::cout << i << ": ";
            Node<key_type> *ptr = array[i].next;
            while (ptr != NULL)
            {
                std::cout << ptr->data << " ->";
                ptr = ptr->next;
            }
            std::cout << "NULL\n";
        }
    }
    class iterator
    {
    private:
        Node<key_type> *ptr;
        int &iter_size;
        int size;
        Node<key_type> *array;

    public:
        iterator(Node<key_type> *p, int &iter_size, int size, Node<key_type> *array)
            : ptr(p), iter_size(iter_size), size(size), array(array) {}

        key_type &operator*()
        {
            return ptr->data;
        }

        iterator &operator++()
        {
            if (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            else
            {
                iter_size++;
                while (iter_size < size && array[iter_size].next == NULL)
                {
                    iter_size++;
                }
                if (iter_size < size)
                {
                    ptr = array[iter_size].next;
                }
                else
                {
                    ptr = NULL;
                }
            }

            return *this;
        }

        bool operator!=(const iterator &other) const
        {
            return ptr != other.ptr;
        }
    };

    iterator begin()
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i].next != NULL)
            {
                iter_size = i;
                return iterator(array[i].next, iter_size, size, array);
            }
        }
        return end();
    }

    iterator end()
    {
        return iterator(NULL, iter_size, size, array);
    }
};

int main()
{
    hash<int> obj_1;
    obj_1.insert(14);
    obj_1.insert(34);
    obj_1.insert(24);
    obj_1.insert(22);
    obj_1.insert(23);
    obj_1.insert(12);
    obj_1.insert(25);
    obj_1.insert(19);

    std::cout << "Displaying values using iterator:\n";
    for (hash<int>::iterator it = obj_1.begin(); it != obj_1.end(); ++it)
    {
        std::cout << *it << " -> \t";
    }
    std::cout << "NULL\n";
    std::cout << "Display all the array and its list : \n";
    std::cout << "--------------------------------\n";

    obj_1.display();
    std::cout << "--------------------------------\n";
    return 0;
}