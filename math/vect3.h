#ifndef VECT3_H
#define VECT3_H

#include <math.h>
// Vector indices 
enum {_x = 0, _y = 1, _z = 2};

template<class DataType>
struct vect3{
  //the 3 vector values
  DataType data[3];
  
  //constructors/destructor
  vect3(){};
  vect3(DataType x, DataType y, DataType z){data[_x]=x; data[_y]=y; data[_z]=z;};
  ~vect3(){};
  
  // overloaded operators 
  
  //subscript reference
  inline DataType& operator[](int i) {return (data[i]);};
  inline const DataType& operator[](int i) const {return (data[i]);};
  
  //assignment
  inline vect3& operator=(const vect3 &v) {
    if (this!=&v){
      data[_x]=v[_x];
      data[_y]=v[_y];
      data[_z]=v[_z];
    }
    return (*this);
  }
  // negate
  inline vect3& operator-() {
    data[_x]=-data[_x];
    data[_y]=-data[_y];
    data[_z]=-data[_z];
    return (*this);
  }
  
  //equality
  inline bool operator==(const vect3& v) {
    return (
	    (v[_x] == data[_x]) && 
	    (v[_y] == data[_y]) && 
	    (v[_z] == data[_z]));
	}
  
  //not equality
  inline bool operator!=(const vect3& v) {
    return ~(
	     (v[_x] == data[_x]) && 
	     (v[_y] == data[_y]) && 
	     (v[_z] == data[_z]));
	}
  
  //scalar (dot) product - implemented as overloaded %
  inline DataType operator%(const vect3& v) {
    return (data[_x] * v[_x] + 
						data[_y] * v[_y] + 
						data[_z] * v[_z]);
  }

  //vector product...
  friend inline vect3 operator*(const vect3& v1, const vect3& v2) {
    vect3 res;
    res[_x] = v1[_y] * v2[_z] - v1[_z] * v2[_y];
    res[_y] = v1[_z] * v2[_x] - v1[_x] * v2[_z];
    res[_z] = v1[_x] * v2[_y] - v1[_y] * v2[_x];
    return(res);
	}

  //vector add
  friend inline vect3 operator+(const vect3& v1, const vect3& v2) {
    vect3 res;
    res[_x]=v1[_x]+v2[_x];
    res[_y]=v1[_y]+v2[_y];
    res[_z]=v1[_z]+v2[_z];
    return (res);
	}

  inline void operator+=(const vect3& v) {
    data[_x]+=v[_x];
    data[_y]+=v[_y];
    data[_z]+=v[_z];
  }

  //vector subtract
  friend inline vect3 operator-(const vect3& v1, const vect3& v2) {
    vect3 res;
    res[_x]=v1[_x]-v2[_x];
    res[_y]=v1[_y]-v2[_y];
    res[_z]=v1[_z]-v2[_z];
    return (res);
	}

  inline void operator-=(const vect3& v) {
    data[_x]-=v[_x];
    data[_y]-=v[_y];
    data[_z]-=v[_z];
  }


  //scalar multiply
  friend inline vect3 operator*(const vect3& v, const DataType& a) {
    vect3 res;
    res[_x]=v[_x]*a;
    res[_y]=v[_y]*a;
    res[_z]=v[_z]*a;
    return (res);
	}

  inline void operator*=(const DataType& a) {
    data[_x]*=a;
    data[_y]*=a;
    data[_z]*=a;
  }


  //scalar add
  friend inline vect3 operator+(const vect3& v, const DataType& a) {
    vect3 res;
    res[_x]=v[_x]+a;
    res[_y]=v[_y]+a;
    res[_z]=v[_z]+a;
    return (res);
	}
  
  inline void operator+=(const DataType& a) {
    data[_x]+=a;
    data[_y]+=a;
    data[_z]+=a;
  }


  //scalar divide
  friend inline vect3 operator/(const vect3& v, const DataType& a) {
    vect3 res;
    res[_x]=v[_x]/a;
    res[_y]=v[_y]/a;
    res[_z]=v[_z]/a;
    return (res);};

  inline void operator/=(const DataType& a) {
    data[_x]/=a;
    data[_y]/=a;
    data[_z]/=a;
  }


  //scalar subtract
  friend inline vect3 operator-(const vect3& v, const DataType& a) {
    vect3 res;
    res[_x]=v[_x]-a;
    res[_y]=v[_y]-a;
    res[_z]=v[_z]-a;
    return (res);};

  inline void operator-=(const DataType& a) {
    data[_x]-=a;
    data[_y]-=a;
    data[_z]-=a;
  }

  //member functions
  inline void assign(DataType x, DataType y, DataType z)
  {
    data[_x]=x; 
    data[_y]=y; 
    data[_z]=z;
  }


  inline DataType length() {
    return((DataType) 
  					sqrt((DataType)(data[_x] * data[_x]) + (DataType)(data[_y] * data[_y]) + 
	  						 (DataType)(data[_z] * data[_z])));
  }

  inline void normalize() {
    DataType Dist = (DataType) 1.0 / length();
    (*this) *= Dist;
  }

  inline void plus_fac(vect3& A, vect3& B, const DataType& t) 
  {
    data[_x] = A[_x] + (t) * B[_x];
    data[_y] = A[_y] + (t) * B[_y];
    data[_z] = A[_z] + (t) * B[_z];
  }

  inline void plus_fac2(const vect3& A, const vect3& B, const DataType& b, const vect3& C, const DataType& c) 
  {
    data[_x] = A[_x] + (b) * B[_x] + (c) * C[_x];
    data[_y] = A[_y] + (b) * B[_y] + (c) * C[_y];
    data[_z] = A[_z] + (b) * B[_z] + (c) * C[_z];
  }
  
  inline void combine(const vect3& A, const DataType& a, const vect3& B, const DataType& b)
  {
    data[_x] = (a) * A[_x] + (b) * B[_x];
    data[_y] = (a) * A[_y] + (b) * B[_y];
    data[_z] = (a) * A[_z] + (b) * B[_z];
  }

  inline void lerp(const DataType& a, const vect3& v)
  {
    data[_x]= data[_x] +((v[_x] - data[_x]) * a);
    data[_y]= data[_y] +((v[_y] - data[_y]) * a);
    data[_z]= data[_z] +((v[_z] - data[_y]) * a);
  }

  inline vect3 Util_t(const vect3& A1, const vect3& A2, const vect3& A3)
  {
    vect3 res;
    res[_x] = (*this)%A1;
    res[_y] = (*this)%A2;
    res[_z] = (*this)%A3;
    return (res);
  }

  inline void convert(DataType *arr)
  {
    arr[_x]=data[_x];
    arr[_y]=data[_y];
    arr[_z]=data[_z];
  }

  inline void SetToMaxOf(const vect3& v)
  {
    if (data[_x]<v[_x]) data[_x]=v[_x];
    if (data[_y]<v[_y]) data[_y]=v[_y];
    if (data[_z]<v[_z]) data[_z]=v[_z];
  }

  inline void SetToMinOf(const vect3& v)
  {
    if (data[_x] > v[_x]) data[_x]=v[_x];
    if (data[_y] > v[_y]) data[_y]=v[_y];
    if (data[_z] > v[_z]) data[_z]=v[_z];
  }

};

#endif
