//
// Created by 20619 on 2025/11/14.
//

#ifndef KINGDOMRUSH_STU_SLOTMENU_H
#define KINGDOMRUSH_STU_SLOTMENU_H

#include "cocos2d.h"
USING_NS_CC;
class SlotMenu : public Sprite{
public:
    SlotMenu();
    ~SlotMenu();
    virtual bool initWithNum(int num);//接收num参数以明确是哪个存档槽
    CREATE_FUNC(SlotMenu);
    void createNewGame();
    static SlotMenu* createMenu(int num);

    void button_Savelot_Delete_callback(Ref* pSender);
    void conform_delete(Ref* pSender);
    void cancel_delete(Ref* pSender);//确认/取消删除
    void deleteRecord(int num);//清除所有数据
protected:
    Label* label_hint;//“删除”提示标签
    MenuItemSprite* button_Savelot_Delete;//“删除”按钮
    Sprite* savelot;//槽位背景精灵
    CC_SYNTHESIZE(int, num, Num);
};

#endif //KINGDOMRUSH_STU_SLOTMENU_H