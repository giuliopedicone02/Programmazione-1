#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
using namespace std;

#define DIM 10

template <typename T>
class AbstractVec
{
private:
    T **data;

protected:
    int max_size;
    int read_index;
    int write_index;

    T *get(int index)
    {
        return data[index];
    }
    bool exists(int index)
    {
        if (data[index])
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void set(int i, T x)
    {
        *data[i] = x;
    }

public:
    AbstractVec(int maxsize) : read_index(0), write_index(0)
    {
        max_size = maxsize;

        data = new T *[max_size];
        for (int c = 0; c < max_size; c++)
        {
            data[c] = new T;
        }
    }

    virtual T *next() = 0;
    virtual bool insert(T x) = 0;

    int len()
    {
        int counter = 0;
        for (int c = 0; c < max_size; c++)
        {
            if (data[c])
            {
                counter++;
            }
        }

        return counter;
    }

    void shuffle()
    {
        for (int c = 0; c < max_size; c++)
        {
            if (data[c])
            {
                for (int i = c; i < max_size; i++)
                {
                    if (data[i])
                    {
                        T *aux = nullptr;
                        aux = data[c];
                        data[c] = data[i];
                        data[i] = aux;
                    }
                }
            }
        }
    }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ", max_size = " << max_size << ", vec = [ ";

        for (int c = 0; c < max_size; c++)
        {
            os << *data[c] << " ";
        }

        os << "], len() = " << len();

        return os;
    }
};

template <typename T>
ostream &operator<<(ostream &os, AbstractVec<T> &obj)
{
    return obj.put(os);
};

template <typename T>
class PlainVec : public AbstractVec<T>
{
public:
    PlainVec(int max_size) : AbstractVec<T>(max_size) {}

    T *next()
    {
        if (AbstractVec<T>::read_index <= AbstractVec<T>::max_size)
        {
            AbstractVec<T>::read_index++;
            return AbstractVec<T>::get(AbstractVec<T>::read_index);
        }
        else
        {
            return nullptr;
        }
    }
    bool insert(T x)
    {
        if (AbstractVec<T>::write_index <= AbstractVec<T>::max_size)
        {
            AbstractVec<T>::set(AbstractVec<T>::write_index, x);
            return true;
        }
        else
        {
            return false;
        }
    }
    ostream &put(ostream &os)
    {
        AbstractVec<T>::put(os);

        //...

        return os;
    }
};
template <typename T>
class CircularVec : public AbstractVec<T>
{
private:
    int cycles;

public:
    CircularVec(int max_size) : AbstractVec<T>(max_size), cycles(0) {}

    T *next()
    {
        T *result = AbstractVec<T>::get(AbstractVec<T>::read_index);
        AbstractVec<T>::read_index++;

        if (AbstractVec<T>::read_index == AbstractVec<T>::max_size)
        {
            AbstractVec<T>::read_index = 0;
            cycles++;
        }

        return result;
    }

    bool insert(T x)
    {
        AbstractVec<T>::set(AbstractVec<T>::write_index, x);
        AbstractVec<T>::write_index++;

        if (AbstractVec<T>::write_index == AbstractVec<T>::max_size)
        {
            AbstractVec<T>::write_index = 0;
            cycles++;
        }

        return true;
    }

    ostream &put(ostream &os)
    {
        AbstractVec<T>::put(os);

        os << ", cycles = " << cycles;

        return os;
    }
};

int main()
{
    srand(424242);

    AbstractVec<int> *vec[DIM];

    for (int i = 0; i < DIM; i++)
    {
        int size = rand() % 16 + 5;

        if (rand() % 2)
        {
            vec[i] = new PlainVec<int>(size);
        }
        else
        {
            vec[i] = new CircularVec<int>(size);
        }
    }

    for (int i = 0; i < DIM * 5; i++)
    {
        int x = rand() % 100;
        vec[x % DIM]->insert(x);
    }

    for (int i = 0; i < DIM; i++)
    {
        vec[i]->shuffle();
    }

    // Punto 1

    for (int c = 0; c < DIM; c++)
    {
        cout << c << ") " << *vec[c] << endl;
    }

    // Punto 2

    int min = vec[0]->len();

    for (int c = 0; c < DIM; c++)
    {
        if (min < vec[c]->len())
        {
            min = vec[c]->len();
        }
    }

    cout << "Minino len() : " << min;
}