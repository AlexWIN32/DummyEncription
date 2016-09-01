/*******************************************************************************
    Author: Alexey Frolov (alexwin32@mail.ru)

    This software is distributed freely under the terms of the MIT License.
    See "LICENSE" or "http://copyfree.org/content/standard/licenses/mit/license.txt".
*******************************************************************************/

#pragma once
#include <math.h>
#include <vector>
#include <Vector2Fwd.h>

template<class T>
struct BaseVector2
{	
	T x, y;
	BaseVector2(float X, float Y):x(X), y(Y){}
	BaseVector2() : x(T()), y(T()){}
	static float Dot(const BaseVector2<T> &A, const BaseVector2<T> &B) 
	{
		return A.x * B.x + A.y * B.y;
	}	
	float Lenght() { return sqrt((x * x) + (y * y));}	
	void Normalize()
	{
		float len = Lenght();
		x /= len;
		y /= len;
	}
	BaseVector2<T> operator + ( const BaseVector2<T> &Val) const
	{
		return BaseVector2<T>(x + Val.x, y + Val.y);
	}
    BaseVector2<T> operator + () const
    {
        return *this;
    }
    BaseVector2<T> operator - ( const BaseVector2<T> &Val) const
	{
		return BaseVector2<T>(x - Val.x, y - Val.y);
	}
	const BaseVector2<T> operator - () const
	{
		return BaseVector2<T>(-x, -y);
	}
	BaseVector2<T> operator * ( const T &Val) const
	{
		return BaseVector2<T>(x * Val, y * Val);
	}
	BaseVector2<T> operator / ( const T &Val) const
	{
		return BaseVector2<T>(x / Val, y / Val);
	}
	BaseVector2<T>& operator += ( const BaseVector2<T> &Val)
	{
		x += Val.x;
		y += Val.y;
		return *this;
	}
	BaseVector2<T>& operator -= ( const BaseVector2<T> &Val)
	{
		x -= Val.x;
		y -= Val.y;
		return *this;
	}    
	BaseVector2<T>& operator *= ( const T &Val)
	{
		x *= Val;
		y *= Val;
		return *this;
	}        
	BaseVector2<T>& operator /= ( const T &Val)
	{
		x /= Val;
		y /= Val;
		return *this;
	}
	bool operator == (const BaseVector2<T> & Val) const
	{
		return x == Val.x && y == Val.y; 
	}
	bool operator != (const BaseVector2<T> & Val) const
	{
		return !operator == (Val);
	}
};

template<class T>
struct BaseVector3
{
    T x = T(), y = T(), z = T();
    BaseVector3(){}
    BaseVector3(T X, T Y, T Z) : x(X), y(Y), z(Z){}
    static float Dot(const BaseVector3<T> &A, const BaseVector3<T> &B) 
    {
        return A.x * B.x + A.y * B.y + A.z * B.z;
    }
    static BaseVector3<T> Cross(const BaseVector3<T> &A, const BaseVector3<T> &B)
    {
        BaseVector3<T> out;
        out.x = A.y * B.z - A.z * B.y;
        out.y = A.z * B.x - A.x * B.z;
        out.z = A.x * B.y - A.y * B.x;
        return out;
    }
    float Lenght() { return sqrt((x * x) + (y * y) + (z * z));}
    void Normalize()
    {
        float len = Lenght();
        x /= len;
        y /= len;
        z /= len;
    }
    BaseVector3<T> operator + ( const BaseVector3<T> &Val) const
    {
        return {x + Val.x, y + Val.y, z + Val.z};
    }
    BaseVector2<T> operator + () const
    {
        return *this;
    }
    BaseVector3<T> operator - ( const BaseVector3<T> &Val) const
    {
        return {x - Val.x, y - Val.y, z - Val.z};
    }
    const BaseVector3<T> operator - () const
    {
        return {-x, -y, -z};
    }
    BaseVector3<T> operator * ( const T &Val) const
    {
        return {x * Val, y * Val, z * Val};
    }
    BaseVector3<T> operator / ( const T &Val) const
    {
        return {x / Val, y / Val, z / Val};
    }
    BaseVector3<T>& operator += ( const BaseVector3<T> &Val)
    {
        x += Val.x;
        y += Val.y;
        z += Val.z;
        return *this;
    }
    BaseVector3<T>& operator -= ( const BaseVector3<T> &Val)
    {
        x -= Val.x;
        y -= Val.y;
        z -= Val.z;
        return *this;
    }
    BaseVector3<T>& operator *= ( const T &Val)
    {
        x *= Val;
        y *= Val;
        z *= Val;
        return *this;
    }
    BaseVector3<T>& operator /= ( const T &Val)
    {
        x /= Val;
        y /= Val;
        z /= Val;
        return *this;
    }
    bool operator == (const BaseVector3<T> & Val) const
    {
        return x == Val.x && y == Val.y && z == Val.z; 
    }
    bool operator != (const BaseVector3<T> & Val) const
    {
        return !operator == (Val);
    }
};

template<class T>
struct BasePoint2
{
	T x, y;
	BasePoint2(T X, T Y) : x(X), y(Y) {}
	BasePoint2() : x(T()), y(T()){}
	BasePoint2<T> operator + ( const BasePoint2<T> &Val) const
	{
		return BasePoint2<T>(x + Val.x, y + Val.y);
	}
    BasePoint2<T> operator - ( const BasePoint2<T> &Val) const
	{
		return BasePoint2<T>(x - Val.x, y - Val.y);
	}

	BasePoint2<T> operator + ( const BaseVector2<T> &Val) const
	{
		return BasePoint2<T>(x + Val.x, y + Val.y);
	}
    BasePoint2<T> operator - ( const BaseVector2<T> &Val) const
	{
		return BasePoint2<T>(x - Val.x, y - Val.y);
	}

	BasePoint2<T> operator * ( const T &Val) const
	{
		return BasePoint2<T>(x * Val, y * Val);
	}
	BasePoint2<T> operator / ( const T &Val) const
	{
		return BasePoint2<T>(x / Val, y / Val);
	}
	BasePoint2<T>& operator += ( const BasePoint2<T> &Val)
	{
		x += Val.x;
		y += Val.y;
		return *this;
	}
	BasePoint2<T>& operator -= ( const BasePoint2<T> &Val)
	{
		x -= Val.x;
		y -= Val.y;
		return *this;
	}    
	BasePoint2<T>& operator += ( const BaseVector2<T> &Val)
	{
		x += Val.x;
		y += Val.y;
		return *this;
	}
	BasePoint2<T>& operator -= ( const BaseVector2<T> &Val)
	{
		x -= Val.x;
		y -= Val.y;
		return *this;
	}  
	BasePoint2<T>& operator *= ( const T &Val)
	{
		x *= Val;
		y *= Val;
		return *this;
	}        
	BasePoint2<T>& operator /= ( const T &Val)
	{
		x /= Val;
		y /= Val;
		return *this;
	}
	bool operator == (const BasePoint2<T> & Val) const
	{
		return x == Val.x && y == Val.y; 
	}
	bool operator != (const BasePoint2<T> & Val) const
	{
		return !operator == (Val);
	}
    BasePoint2<T> operator - () const
    {
        return BasePoint2<T>(-x, -y);
    }
    BasePoint2<T> operator + () const
    {
        return *this;
    }
};

template<class T>
struct BasePoint3
{
    T x = T(), y = T(), z = T();
    BasePoint3(){}
    BasePoint3(T X, T Y, T Z) : x(X), y(Y), z(Z){}
    BasePoint3(const BaseVector3<T> &V): x(V.x), y(V.y), z(V.z){}
    BasePoint3<T> operator + ( const BasePoint3<T> &Val) const
    {
        return {x + Val.x, y + Val.y, z + Val.z};
    }
    BasePoint3<T> operator - ( const BasePoint3<T> &Val) const
    {
        return {x - Val.x, y - Val.y, z - Val.z};
    }
    BasePoint3<T> operator + ( const BaseVector3<T> &Val) const
    {
        return {x + Val.x, y + Val.y, z + Val.z};
    }
    BasePoint3<T> operator - ( const BaseVector3<T> &Val) const
    {
        return {x - Val.x, y - Val.y, z - Val.z};
    }
    BasePoint3<T> operator * ( const T &Val) const
    {
        return {x * Val, y * Val, z * Val};
    }
    BasePoint3<T> operator / ( const T &Val) const
    {
        return {x / Val, y / Val, z / Val};
    }
    BasePoint3<T>& operator += ( const BasePoint3<T> &Val)
    {
        x += Val.x;
        y += Val.y;
        z += Val.z;
        return *this;
    }
    BasePoint3<T>& operator -= ( const BasePoint3<T> &Val)
    {
        x -= Val.x;
        y -= Val.y;
        z -= Val.z;
        return *this;
    }
    BasePoint3<T>& operator += ( const BaseVector3<T> &Val)
    {
        x += Val.x;
        y += Val.y;
        z += Val.z;
        return *this;
    }
    BasePoint3<T>& operator -= ( const BaseVector3<T> &Val)
    {
        x -= Val.x;
        y -= Val.y;
        z -= Val.z;
        return *this;
    }
    BasePoint3<T>& operator *= ( const T &Val)
    {
        x *= Val;
        y *= Val;
        z *= Val;
        return *this;
    }
    BasePoint3<T>& operator /= ( const T &Val)
    {
        x /= Val;
        y /= Val;
        z /= Val;
        return *this;
    }
    bool operator == (const BasePoint3<T> & Val) const
    {
        return x == Val.x && y == Val.y && z == Val.z; 
    }
    bool operator != (const BasePoint3<T> & Val) const
    {
        return !operator == (Val);
    }
    BasePoint3<T> operator - () const
    {
        return {-x, -y, -z};
    }
    BasePoint3<T> operator + () const
    {
        return *this;
    }
};

template<class T>
struct Size
{
	T width, height;
	Size(T Width, T Height):width(Width), height(Height){}
	Size() :width(T()), height(T()){}		
	Size<T> operator + ( const Size<T> &Val) const
	{
		return Size<T>(width + Val.width, height + Val.height);
	}
    Size<T> operator - ( const Size<T> &Val) const
	{
		return Size<T>(width - Val.width, height - Val.height);
	}
	Size<T> operator * ( const T &Val) const
	{
		return Size<T>(width * Val, height * Val);
	}
	Size<T> operator / ( const T &Val) const
	{
		return Size<T>(width / Val, height / Val);
	}
	Size<T>& operator += ( const Size<T> &Val)
	{
		width += Val.width;
		height += Val.height;
		return *this;
	}
	Size<T>& operator -= ( const Size<T> &Val)
	{
		width -= Val.width;
		height -= Val.height;
		return *this;
	}    
	Size<T>& operator *= ( const T &Val)
	{
		width *= Val;
		height *= Val;
		return *this;
	}        
	Size<T>& operator /= ( const T &Val)
	{
		width /= Val;
		height /= Val;
		return *this;
	}
	bool operator == (const Size<T> & Val) const
	{
		return width == Val.width && height == Val.height; 
	}
	bool operator != (const Size<T> & Val) const
	{
		return !operator == (Val);
	}
};

template<class T>
struct Range
{
	T minVal, maxVal;
	Range(T MinVal, T MaxVal) : minVal(MinVal), maxVal(MaxVal){}
	Range():minVal(T()),maxVal(T()){}
	Range<T> operator + ( const Range<T> &Val) const
	{
		return Range<T>(minVal + Val.minVal, maxVal + Val.maxVal);
	}
    Range<T> operator - ( const Range<T> &Val) const
	{
		return Range<T>(minVal - Val.minVal, maxVal - Val.maxVal);
	}
	Range<T> operator * ( const T &Val) const
	{
		return Range<T>(minVal * Val, maxVal * Val);
	}
	Range<T> operator / ( const T &Val) const
	{
		return Range<T>(minVal / Val, maxVal / Val);
	}
	Range<T>& operator += ( const Range<T> &Val)
	{
		minVal += Val.minVal;
		maxVal += Val.maxVal;
		return *this;
	}
	Range<T>& operator -= ( const Range<T> &Val)
	{
		minVal -= Val.minVal;
		maxVal -= Val.maxVal;
		return *this;
	}    
	Range<T>& operator *= ( const T &Val)
	{
		minVal *= Val;
		maxVal *= Val;
		return *this;
	}        
	Range<T>& operator /= ( const T &Val)
	{
		minVal /= Val;
		maxVal /= Val;
		return *this;
	}
	bool operator == (const Range<T> & Val) const
	{
		return minVal == Val.minVal && maxVal == Val.maxVal; 
	}
	bool operator != (const Range<T> & Val) const
	{
		return !operator == (Val);
	}
};

class Directions
{
private:
	std::vector<Point2> directions;
public:
	Directions()
	{
		directions.push_back(Point2(-1,  0));
		directions.push_back(Point2(-1, -1));
		directions.push_back(Point2( 0, -1));
		directions.push_back(Point2( 1, -1));						
		directions.push_back(Point2( 1,  0));
		directions.push_back(Point2( 1,  1));
		directions.push_back(Point2( 0,  1));
		directions.push_back(Point2(-1,  1));	
	}	
	const Point2 &operator [] (int Ind){return directions[Ind];}
};

#define Pi 3.141592654f //TODO make static const float Pi 

template<class T>
T Cast(const Vector2 &Val){ return T(Val.x, Val.y);}

template<class T>
T Cast(const Point2 &Val){ return T(Val.x, Val.y);}

template<class T>
T Cast(const Point2F &Val){ return T(Val.x, Val.y);}

template<class T>
T Cast(const Point2US &Val){ return T(Val.x, Val.y);}

template<class T>
T Cast(const SizeUS &Val){ return T(Val.width, Val.height);}

template<class T>
T Cast(const SizeF &Val){ return T(Val.width, Val.height);}

template<class T>
float Disstance(const T &Point1, const T &Point2)
{
	T del = Point2 - Point1;
	return (del.x * del.x) + (del.y * del.y);
}