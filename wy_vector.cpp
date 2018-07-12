#include<stdlib.h>
#include<cstddef>
#ifndef VECTOR_WY
#define VECTOR_WY
template<typename T>
class vector
{
public:
    using iterator=T*;
    using difference_type=ptrdiff_t;
    using const_iterator=T*;
    using value_type=T;
    class reverse_iterator
    {
        private :
        T* t;
    public:
        reverse_iterator(T *_t = nullptr) : t(_t){}
        reverse_iterator& operator++()
        {
            return t;
        }
        reverse_iterator& operator--()
        {
            return t;
        }
        reverse_iterator operator++( int )
        {
            return --t;
        }
        reverse_iterator operator--( int )
        {
            return ++t;
        }
        reverse_iterator& operator+=( difference_type n )
        {
            return t;
        }
        reverse_iterator& operator-=( difference_type n )
        {
            return t;
        }

    };
    private :
    size_t thesize;
    size_t thecapacity;
    T* Obj;
public:
    vector ()
    {
        thesize=0;
        thecapacity=5;
        Obj=new T*[thecapacity];
    }
    explicit vector( size_t count )
    {
        thesize=count;
        thecapacity=2*count+1;
        Obj=new T*[thecapacity];
    }
     vector(size_t count,value_type n)
     {
        thesize=count;
        thecapacity=2*count+1;
        Obj=new T*[thecapacity];
        for(auto i=0;i<count;i++)
            Obj[i]=n;
     }
     ~vector()
     {
        delete[] Obj;
     }
     void push_back(size_t n)
     {
        if(thesize==thecapacity)
            {
                reserve(2*thesize+1);
            }
        Obj[thesize++]=n;
     }
     void pop_back()
     {
        thesize--;
     }
     void assign(size_t count,value_type value)
     {
        if(thesize<count)
        {
            auto i=0;
            for(;i<thesize;i++)
                Obj[i]=value;
            for(;i<count;i++)
                push_back(value);
        }
        else
        {
            thesize=count;
            for(auto i=0;i<thesize;i++)
                Obj[i]=value;
        }
     }
    iterator at(size_t pos )
    {
        if(pos>thesize||pos<0)
            return 0;
        return pos;
    }
    T* data() noexcept
    {
        return Obj;
    }
     iterator begin()
     {
        return Obj;
     }
     const_iterator cbegin() const noexcept
     {
        return Obj;
     }
     iterator end()
     {
        return Obj+thesize;
     }
     const_iterator cend() const noexcept
     {
        return Obj+thesize;
     }
     reverse_iterator rbegin()
     {
        return Obj+thesize-1;
     }
     const reverse_iterator rbegin() const noexcept
     {
        return Obj+thesize-1;
     }

     reverse_iterator rend()
     {
        return Obj-1;
     }
     const reverse_iterator rend() const noexcept
     {
        return Obj-1;
     }
     bool empty() const
     {
        if(thesize==0)
            return 1;
        else
            return 0;
     }
     size_t size()const
    {
        return thesize;
    }
    void reserve(size_t new_cap)
    {
        if(thesize>=new_cap)
            return;
        T* Objs=Obj;
        T* Obj=new T* [thecapacity];
        for(auto i=0;i<thecapacity;i++)
            Obj[i]=Objs[i];
        delete [] Objs;
    }
    size_t capacity() const
    {
        return capacity;
    }
    void shrink_to_fit()
    {
        thecapacity=thesize;
        T* Objs=Obj;
        T* newdata=new T* [thecapacity];
        for(auto i=0;i<thecapacity;i++)
            newdata[i]=Obj[i];
        Obj=newdata;
        delete [] Objs;
    }
    void clear()
    {
        thesize=0;
    }
    void insert(size_t pos,value_type value )
    {
        thesize++;
        if(thesize==thecapacity)
        {
            reserve(2*thesize+1);
        }
        for(auto i=pos;i<thesize;i++)
            Obj[i+1]=Obj[i];
        Obj[pos]=value;
    }
    void erase(size_t pos)
    {
           thesize--;
        for(auto i=pos;i<thesize;i++)
            Obj[i]=Obj[i+1];
        return begin()+pos;
    }
    void resize(size_t count )
    {
        if(thesize<=count)
            reserve(count*2+1);
        thesize=count;
    }
    void swap( vector& other )
    {
        T* Objs=Obj;
        Obj=other.Obj;
        other.Obj=Objs;
        size_t tempsize=thesize;
        thesize=other.thesize;
        other.thesize=tempsize;
        size_t tempcapacity=thecapacity;
        thecapacity=other.thecapacity;
        other.thecapacity=tempcapacity;
    }
};
#endif