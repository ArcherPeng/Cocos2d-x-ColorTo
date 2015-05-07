//
//  ColorTo.h
//  Game01
//
//  Created by ArcherPeng on 15/4/8.
//
//

#ifndef __Game01__ColorTo__
#define __Game01__ColorTo__

#include "cocos2d.h"
USING_NS_CC;
class ColorTo : public ActionInterval
{
public:
    /**
     * Creates the action.
     *
     * @param 播放动画总共的时间
     * @param 颜色的偏移量
     * @return An autoreleased ColorTo object.
     */
    static ColorTo* create(float duration, const Color3B& endColor);
    
    //
    // Overrides
    //
    virtual ColorTo* clone() const override;
    virtual ColorTo* reverse(void) const  override;
    virtual void startWithTarget(Node *target) override;
    /**
     * @param time in seconds
     */
    virtual void update(float time) override;
    
CC_CONSTRUCTOR_ACCESS:
    ColorTo(){}
    virtual ~ColorTo() {}
    
    /** initializes the action */
    bool initWithDuration(float duration, const Color3B& endColor);
    
protected:
    Color3B _startC3b;
    Color3B _endC3b;
private:
    CC_DISALLOW_COPY_AND_ASSIGN(ColorTo);

};


#endif /* defined(__Game01__ColorTo__) */
