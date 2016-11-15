//
// Created by joar on 11/13/16.
//

#include "ObjectClickable.h"

ObjectClickable::ObjectClickable(ObjectInterface::ShapeType shape_type,
                                 ObjectInterface::DerivedClassType derivedClass,
                                 bool clickable)
        : ObjectInterface(shape_type, derivedClass, clickable) {}
