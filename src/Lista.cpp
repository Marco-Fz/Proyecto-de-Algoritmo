#include "Lista.h"
template<typename T> Lista<T>::Lista()
{
    l = NULL;

}

template<typename T> Lista<T>::~Lista()
{

}

template<typename T> void Lista<T>::P()
{
    Nodo*aux =l;
    while(aux!=NULL){
        cout<<aux->elemento<<endl;
        aux=aux->sig;
    }
}
template<typename T> void Lista<T>::agregar(const T & e)
{

    Nodo * aux = NULL;
    if(l == NULL)
    {
        aux=new Nodo;
        aux->elemento = e;
        aux->sig = NULL;
        l=aux;
    }

    else
    {
        aux=l;
        l=new Nodo;
        l->elemento=e;
        l->sig=aux;
    }
}

template<typename T> bool Lista<T>::vacia()const
{
    return (l == NULL);
}


template<typename T> bool Lista<T>::pertenece(const T & elemento)const
{
    if(l != NULL)
    {
        Nodo * aux = l;
        while(aux != NULL)
        {
            if(elemento == aux->elemento)
            {
                return (true);
            }else
            {
                aux = aux->sig;
            }
        }
        return(false);
    }
    else
    return (false);
}
template class Lista<int>;
