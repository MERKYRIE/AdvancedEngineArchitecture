// Copyright (c) 1997-2021
// Utrecht University (The Netherlands),
// ETH Zurich (Switzerland),
// INRIA Sophia-Antipolis (France),
// Max-Planck-Institute Saarbruecken (Germany),
// and Tel-Aviv University (Israel).
// GeometryFactory (France)
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org)
//
// $URL: https://github.com/CGAL/cgal/blob/v5.6/Intersections_3/include/CGAL/Intersections_3/Point_3_Sphere_3.h $
// $Id: Point_3_Sphere_3.h c2d1adf 2021-06-23T17:34:48+02:00 Mael Rouxel-Labbé
// SPDX-License-Identifier: LGPL-3.0-or-later OR LicenseRef-Commercial
//
//
// Author(s)     : Maxime Gimeno

#ifndef CGAL_INTERSECTIONS_3_POINT_3_SPHERE_3_H
#define CGAL_INTERSECTIONS_3_POINT_3_SPHERE_3_H

#include <../CGALOSP/Intersection_traits_3.h>
#include <../CGALOSP/Intersections_3/internal/Point_3_Sphere_3_do_intersect.h>
#include <../CGALOSP/Intersections_3/internal/Point_3_Sphere_3_intersection.h>

#include <../CGALOSP/Point_3.h>
#include <../CGALOSP/Sphere_3.h>

namespace CGAL {

CGAL_DO_INTERSECT_FUNCTION(Point_3, Sphere_3, 3)
CGAL_INTERSECTION_FUNCTION(Point_3, Sphere_3, 3)

} // namespace CGAL

#endif // CGAL_INTERSECTIONS_3_POINT_3_SPHERE_3_H
