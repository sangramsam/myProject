///////////////////////////////////////////////////////////////////////////////
//
//  globals.inl                                 Author:     Eric McDaniel
//                                              Email:      chate@cs.wisc.edu
//                                              Written:    Summer 2002
//
//      Definitions of the global methods for this application.
//
///////////////////////////////////////////////////////////////////////////////

// global functions

///////////////////////////////////////////////////////////////////////////////
//
//      Get the minimum of two values.  Note:  operator < must be defined for
//  the given type.
//
///////////////////////////////////////////////////////////////////////////////
template<class TType>
inline TType Min(TType valueA, TType valueB)
{
    return ((valueA < valueB) ? valueA : valueB);
}// Min


///////////////////////////////////////////////////////////////////////////////
//
//      Get the maximum of two values.  Note:  operator < must be defined for
//  the given type.
//
///////////////////////////////////////////////////////////////////////////////
template<class TType>
inline TType Max(TType valueA, TType valueB)
{
    return ((valueA < valueB) ? valueB : valueA);
}// Max

///////////////////////////////////////////////////////////////////////////////
//
//      Convert radians to degrees.
//
///////////////////////////////////////////////////////////////////////////////
inline float RadiansToDegrees(float angle)
{
    return angle * 180.f / g_cPi;
}// RadiansToDegrees


///////////////////////////////////////////////////////////////////////////////
//
//      Convert degress to radians.
//
///////////////////////////////////////////////////////////////////////////////
inline float DegreesToRadians(float angle)
{
    return angle * g_cPi / 180;
}// DegreesToRadians


///////////////////////////////////////////////////////////////////////////////
//
//      Calculate the absolute value of the given item.
//
///////////////////////////////////////////////////////////////////////////////
template<class TType>
inline TType AbsoluteValue(TType value)
{
   return (value >= 0) ? value : -value;
}// AbsoluteValue


///////////////////////////////////////////////////////////////////////////////
//
//      Do the two given values differ by less than epsilon.
//
///////////////////////////////////////////////////////////////////////////////
template<class TTypeA, class TTypeB>
inline bool WithinEpsilon(TTypeA a, TTypeB b)
{
   return AbsoluteValue(a - b) < g_cEpsilon;
}// WithinEpsilon
