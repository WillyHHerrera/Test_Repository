template <class T>
class CadenaDeBloques;

template <class T>
class Bloque {
private:
    T data;
    Bloque<T> *prev;
    Bloque<T> *next;
    size_t hash;
    size_t hash_prev;
    friend class CadenaDeBloques<T>;
public:    
    Bloque(T data) : data(data), prev(nullptr), next(nullptr) {}
};

template <class T>
class CadenaDeBloques {
private:
    Bloque<T> *b_inicio;
    Bloque<T> *b_fin;
    
    size_t hash_function(T data, size_t hash_prev) {

    }
public:
    CadenaDeBloques() : b_inicio(nullptr), b_fin(nullptr) {}

    void push_back(T data) {
        Bloque<T> *nuevo = new Bloque<T>(data);
        if (b_inicio == nullptr) b_inicio = nuevo;
        else {
            b_fin->next = nuevo;
            nuevo->prev = b_fin;
        }
        b_fin = nuevo;
    }    
};