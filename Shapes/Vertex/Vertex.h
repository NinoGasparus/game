#ifndef VERTEX_H
#define VERTEX_H


template <typename T>
class Vertex{
  private:
  public:
    T x;
    T y;
    T z;
    //fix
    Vertex<T>();
    Vertex<T>(T x, T y, T z);
    
    void setZero();
    void scale(T scale);
    void scale(T scaleX, T scaleY, T scaleZ);
    void write(T x, T y, T z);
    ~Vertex<T>();
};


#endif // !VERTEX_H
