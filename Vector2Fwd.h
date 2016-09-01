/*******************************************************************************
    Author: Alexey Frolov (alexwin32@mail.ru)

    This software is distributed freely under the terms of the MIT License.
    See "LICENSE" or "http://copyfree.org/content/standard/licenses/mit/license.txt".
*******************************************************************************/

#pragma once

template<class T>
struct BaseVector2;

template<class T>
struct BasePoint2;

template<typename T>
struct Size;

template<class T>
struct Range;

template<class T>
struct BaseVector3;

template<class T>
struct BasePoint3;

typedef BaseVector3<float> Vector3;
typedef BasePoint3<int> Point3;
typedef BasePoint3<float> Point3F;
typedef BasePoint3<unsigned char> Point3US;
typedef BaseVector2<float> Vector2;
typedef BasePoint2<float> Point2F;
typedef BasePoint2<int> Point2;
typedef BasePoint2<unsigned short> Point2US;
typedef Size<unsigned short> SizeUS;
typedef Size<float> SizeF;
typedef Range<float> RangeF;
typedef Range<unsigned short> RangeUS;
typedef Range<SizeUS> RangeSizeUS;
typedef Range<Vector2> RangeVector2;