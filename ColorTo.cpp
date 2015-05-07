//
//  ColorTo.cpp
//  Game01
//
//  Created by ArcherPeng on 15/4/8.
//
//

#include "ColorTo.h"
//
// 
//



ColorTo* ColorTo::create(float duration, const Color3B& endColor)
{
    ColorTo *ret = new (std::nothrow) ColorTo();
    
    if (ret)
    {
        if (ret->initWithDuration(duration, endColor))
        {
            ret->autorelease();
        }
        else
        {
            delete ret;
            ret = nullptr;
        }
    }
    
    return ret;
}



bool ColorTo::initWithDuration(float duration, const Color3B& endColor)
{
    bool ret = false;
    
    if (ActionInterval::initWithDuration(duration))
    {
        _endC3b = endColor;
        ret = true;
    }
    
    return ret;
}

ColorTo* ColorTo::clone() const
{
    // no copy constructor
    auto a = new (std::nothrow) ColorTo();
    a->initWithDuration(_duration, _endC3b);
    a->autorelease();
    return a;
}

void ColorTo::startWithTarget(Node *target)
{
    ActionInterval::startWithTarget(target);
//    _previousPosition = _startPosition = target->getPosition3D();
    _startC3b = target->getColor();
}

ColorTo* ColorTo::reverse() const
{
    CCASSERT(false, "reverse() not supported in ColorTo");
    return nullptr;
}


void ColorTo::update(float t)
{
    if (_target)
    {
        GLubyte r = (GLubyte)((float)(((float)_endC3b.r - (float)_startC3b.r) * t) +(float)_startC3b.r);
        GLubyte g = (GLubyte)((float)(((float)_endC3b.g - (float)_startC3b.g) * t) +(float)_startC3b.g);
        GLubyte b = (GLubyte)((float)(((float)_endC3b.b - (float)_startC3b.b) * t) +(float)_startC3b.b);
        _target->setColor(Color3B(r, g, b));

    }
}