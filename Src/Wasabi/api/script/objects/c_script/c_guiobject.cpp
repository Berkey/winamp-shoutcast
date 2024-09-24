/* This file was generated by Maki Compiler, do not edit manually */

#include <precomp.h>

#include "c_guiobject.h"
#include <api/script/objcontroller.h>

C_GuiObject::C_GuiObject(ScriptObject *object) : C_RootObject(object) {
  inited = 0;
  obj = NULL;
  C_hook(object);
}

C_GuiObject::C_GuiObject() {
  inited = 0;
  obj = NULL;
}

void C_GuiObject::C_hook(ScriptObject *object) {
  ASSERT(!inited);
  ScriptObjectController *controller = object->vcpu_getController();
  obj = controller->cast(object, guiObjectGuid);
  if (obj != object && obj != NULL)
    controller = obj->vcpu_getController();
  else
    obj = NULL;

  int iter = WASABI_API_APP->app_getInitCount();
  if (!loaded || loaded != iter) {
    loaded = iter;
    show_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"show", this);
    hide_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"hide", this);
    isvisible_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"isVisible", this);
    onsetvisible_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onSetVisible", this);
    setalpha_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setAlpha", this);
    getalpha_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getAlpha", this);
    onleftbuttonup_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onLeftButtonUp", this);
    onleftbuttondown_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onLeftButtonDown", this);
    onrightbuttonup_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onRightButtonUp", this);
    onrightbuttondown_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onRightButtonDown", this);
    onrightbuttondblclk_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onRightButtonDblClk", this);
    onleftbuttondblclk_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onLeftButtonDblClk", this);
    onmousemove_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onMouseMove", this);
    onenterarea_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onEnterArea", this);
    onleavearea_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onLeaveArea", this);
    setenabled_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setEnabled", this);
    getenabled_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getEnabled", this);
    onenable_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onEnable", this);
    resize_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"resize", this);
    onresize_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onResize", this);
    ismouseover_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"isMouseOver", this);
    getleft_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getLeft", this);
    gettop_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getTop", this);
    getwidth_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getWidth", this);
    getheight_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getHeight", this);
    settargetx_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setTargetX", this);
    settargety_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setTargetY", this);
    settargetw_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setTargetW", this);
    settargeth_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setTargetH", this);
    settargeta_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setTargetA", this);
    settargetspeed_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setTargetSpeed", this);
    gototarget_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"gotoTarget", this);
    ontargetreached_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onTargetReached", this);
    canceltarget_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"cancelTarget", this);
    reversetarget_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"reverseTarget", this);
    onstartup_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onStartup", this);
    isgoingtotarget_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"isGoingToTarget", this);
    setxmlparam_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setXmlParam", this);
    getxmlparam_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getXmlParam", this);
    init_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"init", this);
    bringtofront_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"bringToFront", this);
    bringtoback_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"bringToBack", this);
    bringabove_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"bringAbove", this);
    bringbelow_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"bringBelow", this);
    getguix_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getGuiX", this);
    getguiy_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getGuiY", this);
    getguiw_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getGuiW", this);
    getguih_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getGuiH", this);
    getguirelatx_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getGuiRelatX", this);
    getguirelaty_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getGuiRelatY", this);
    getguirelatw_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getGuiRelatW", this);
    getguirelath_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getGuiRelatH", this);
    isactive_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"isActive", this);
    getparent_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getParent", this);
    getparentlayout_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getParentLayout", this);
    gettopparent_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getTopParent", this);
    runmodal_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"runModal", this);
    endmodal_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"endModal", this);
    findobject_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"findObject", this);
    findobjectxy_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"findObjectXY", this);
    getname_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getName", this);
    clienttoscreenx_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"clientToScreenX", this);
    clienttoscreeny_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"clientToScreenY", this);
    clienttoscreenw_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"clientToScreenW", this);
    clienttoscreenh_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"clientToScreenH", this);
    screentoclientx_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"screenToClientX", this);
    screentoclienty_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"screenToClientY", this);
    screentoclientw_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"screenToClientW", this);
    screentoclienth_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"screenToClientH", this);
    getautowidth_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getAutoWidth", this);
    getautoheight_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getAutoHeight", this);
    setfocus_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setFocus", this);
    onchar_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onChar", this);
    onaccelerator_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onAccelerator", this);
    ismouseoverrect_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"isMouseOverRect", this);
    getinterface_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getInterface", this);
    onkeydown_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onKeyDown", this);
    onkeyup_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onKeyUp", this);
    ongetfocus_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onGetFocus", this);
    onkillfocus_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onKillFocus", this);
    sendaction_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"sendAction", this);
    onaction_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onAction", this);
  }
  inited = 1;
}

C_GuiObject::~C_GuiObject() {
}

ScriptObject *C_GuiObject::getScriptObject() {
  if (obj != NULL) return obj;
  return C_GUIOBJECT_PARENT::getScriptObject();
}

void C_GuiObject::show() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), show_id, NULL);
}

void C_GuiObject::hide() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), hide_id, NULL);
}

int C_GuiObject::isVisible() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), isvisible_id, NULL));
}

void C_GuiObject::onSetVisible(int onoff) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(onoff);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onsetvisible_id, params);
}

void C_GuiObject::setAlpha(int alpha) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(alpha);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), setalpha_id, params);
}

int C_GuiObject::getAlpha() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getalpha_id, NULL));
}

void C_GuiObject::onLeftButtonUp(int x, int y) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar b = MAKE_SCRIPT_INT(y);
  scriptVar *params[2] = {&a, &b};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onleftbuttonup_id, params);
}

void C_GuiObject::onLeftButtonDown(int x, int y) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar b = MAKE_SCRIPT_INT(y);
  scriptVar *params[2] = {&a, &b};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onleftbuttondown_id, params);
}

void C_GuiObject::onRightButtonUp(int x, int y) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar b = MAKE_SCRIPT_INT(y);
  scriptVar *params[2] = {&a, &b};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onrightbuttonup_id, params);
}

void C_GuiObject::onRightButtonDown(int x, int y) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar b = MAKE_SCRIPT_INT(y);
  scriptVar *params[2] = {&a, &b};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onrightbuttondown_id, params);
}

void C_GuiObject::onRightButtonDblClk(int x, int y) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar b = MAKE_SCRIPT_INT(y);
  scriptVar *params[2] = {&a, &b};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onrightbuttondblclk_id, params);
}

void C_GuiObject::onLeftButtonDblClk(int x, int y) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar b = MAKE_SCRIPT_INT(y);
  scriptVar *params[2] = {&a, &b};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onleftbuttondblclk_id, params);
}

void C_GuiObject::onMouseMove(int x, int y) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar b = MAKE_SCRIPT_INT(y);
  scriptVar *params[2] = {&a, &b};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onmousemove_id, params);
}

void C_GuiObject::onEnterArea() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onenterarea_id, NULL);
}

void C_GuiObject::onLeaveArea() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onleavearea_id, NULL);
}

void C_GuiObject::setEnabled(int onoff) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(onoff);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), setenabled_id, params);
}

int C_GuiObject::getEnabled() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getenabled_id, NULL));
}

void C_GuiObject::onEnable(int onoff) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(onoff);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onenable_id, params);
}

void C_GuiObject::resize(int x, int y, int w, int h) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar b = MAKE_SCRIPT_INT(y);
  scriptVar c = MAKE_SCRIPT_INT(w);
  scriptVar d = MAKE_SCRIPT_INT(h);
  scriptVar *params[4] = {&a, &b, &c, &d};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), resize_id, params);
}

void C_GuiObject::onResize(int x, int y, int w, int h) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar b = MAKE_SCRIPT_INT(y);
  scriptVar c = MAKE_SCRIPT_INT(w);
  scriptVar d = MAKE_SCRIPT_INT(h);
  scriptVar *params[4] = {&a, &b, &c, &d};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onresize_id, params);
}

int C_GuiObject::isMouseOver(int x, int y) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar b = MAKE_SCRIPT_INT(y);
  scriptVar *params[2] = {&a, &b};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), ismouseover_id, params));
}

int C_GuiObject::getLeft() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getleft_id, NULL));
}

int C_GuiObject::getTop() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), gettop_id, NULL));
}

int C_GuiObject::getWidth() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getwidth_id, NULL));
}

int C_GuiObject::getHeight() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getheight_id, NULL));
}

void C_GuiObject::setTargetX(int x) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), settargetx_id, params);
}

void C_GuiObject::setTargetY(int y) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(y);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), settargety_id, params);
}

void C_GuiObject::setTargetW(int w) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(w);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), settargetw_id, params);
}

void C_GuiObject::setTargetH(int r) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(r);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), settargeth_id, params);
}

void C_GuiObject::setTargetA(int alpha) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(alpha);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), settargeta_id, params);
}

void C_GuiObject::setTargetSpeed(float insecond) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_FLOAT(insecond);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), settargetspeed_id, params);
}

void C_GuiObject::gotoTarget() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), gototarget_id, NULL);
}

void C_GuiObject::onTargetReached() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), ontargetreached_id, NULL);
}

void C_GuiObject::cancelTarget() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), canceltarget_id, NULL);
}

void C_GuiObject::reverseTarget(int reverse) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(reverse);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), reversetarget_id, params);
}

void C_GuiObject::onStartup() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onstartup_id, NULL);
}

int C_GuiObject::isGoingToTarget() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), isgoingtotarget_id, NULL));
}

void C_GuiObject::setXmlParam(const wchar_t *param, const wchar_t *value) 
{
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(param);
  scriptVar b = MAKE_SCRIPT_STRING(value);
  scriptVar *params[2] = {&a, &b};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), setxmlparam_id, params);
}

const wchar_t *C_GuiObject::getXmlParam(const wchar_t *param) 
{
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(param);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_STRING(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getxmlparam_id, params));
}

void C_GuiObject::init(ScriptObject *parent) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_OBJECT(parent);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), init_id, params);
}

void C_GuiObject::bringToFront() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), bringtofront_id, NULL);
}

void C_GuiObject::bringToBack() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), bringtoback_id, NULL);
}

void C_GuiObject::bringAbove(ScriptObject *guiobj) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_OBJECT(guiobj);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), bringabove_id, params);
}

void C_GuiObject::bringBelow(ScriptObject *guiobj) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_OBJECT(guiobj);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), bringbelow_id, params);
}

int C_GuiObject::getGuiX() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getguix_id, NULL));
}

int C_GuiObject::getGuiY() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getguiy_id, NULL));
}

int C_GuiObject::getGuiW() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getguiw_id, NULL));
}

int C_GuiObject::getGuiH() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getguih_id, NULL));
}

int C_GuiObject::getGuiRelatX() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getguirelatx_id, NULL));
}

int C_GuiObject::getGuiRelatY() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getguirelaty_id, NULL));
}

int C_GuiObject::getGuiRelatW() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getguirelatw_id, NULL));
}

int C_GuiObject::getGuiRelatH() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getguirelath_id, NULL));
}

int C_GuiObject::isActive() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), isactive_id, NULL));
}

ScriptObject *C_GuiObject::getParent() {
  ASSERT(inited);
  return GET_SCRIPT_OBJECT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getparent_id, NULL));
}

ScriptObject *C_GuiObject::getParentLayout() {
  ASSERT(inited);
  return GET_SCRIPT_OBJECT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getparentlayout_id, NULL));
}

ScriptObject *C_GuiObject::getTopParent() {
  ASSERT(inited);
  return GET_SCRIPT_OBJECT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), gettopparent_id, NULL));
}

int C_GuiObject::runModal() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), runmodal_id, NULL));
}

void C_GuiObject::endModal(int retcode) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(retcode);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), endmodal_id, params);
}

ScriptObject *C_GuiObject::findObject(const wchar_t *id) 
{
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(id);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_OBJECT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), findobject_id, params));
}

ScriptObject *C_GuiObject::findObjectXY(int x, int y) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar b = MAKE_SCRIPT_INT(y);
  scriptVar *params[2] = {&a, &b};
  return GET_SCRIPT_OBJECT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), findobjectxy_id, params));
}

const wchar_t *C_GuiObject::getName() 
{
  ASSERT(inited);
	return GET_SCRIPT_STRING(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getname_id, NULL));
}

int C_GuiObject::clientToScreenX(int x) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), clienttoscreenx_id, params));
}

int C_GuiObject::clientToScreenY(int y) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(y);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), clienttoscreeny_id, params));
}

int C_GuiObject::clientToScreenW(int w) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(w);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), clienttoscreenw_id, params));
}

int C_GuiObject::clientToScreenH(int h) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(h);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), clienttoscreenh_id, params));
}

int C_GuiObject::screenToClientX(int x) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(x);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), screentoclientx_id, params));
}

int C_GuiObject::screenToClientY(int y) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(y);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), screentoclienty_id, params));
}

int C_GuiObject::screenToClientW(int w) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(w);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), screentoclientw_id, params));
}

int C_GuiObject::screenToClientH(int h) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(h);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), screentoclienth_id, params));
}

int C_GuiObject::getAutoWidth() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getautowidth_id, NULL));
}

int C_GuiObject::getAutoHeight() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getautoheight_id, NULL));
}

void C_GuiObject::setFocus() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), setfocus_id, NULL);
}

void C_GuiObject::onChar(const wchar_t *c) 
{
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(c);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onchar_id, params);
}

void C_GuiObject::onAccelerator(const wchar_t *accel) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(accel);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onaccelerator_id, params);
}

int C_GuiObject::isMouseOverRect() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), ismouseoverrect_id, NULL));
}

ScriptObject *C_GuiObject::getInterface(const wchar_t *interface_guid) 
{
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(interface_guid);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_OBJECT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getinterface_id, params));
}

void C_GuiObject::onKeyDown(int vk_code) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(vk_code);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onkeydown_id, params);
}

void C_GuiObject::onKeyUp(int vk_code) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(vk_code);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onkeyup_id, params);
}

void C_GuiObject::onGetFocus() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), ongetfocus_id, NULL);
}

void C_GuiObject::onKillFocus() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onkillfocus_id, NULL);
}

int C_GuiObject::sendAction(const wchar_t *action, const wchar_t *param, int x, int y, intptr_t p1, intptr_t p2) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(action);
  scriptVar b = MAKE_SCRIPT_STRING(param);
  scriptVar c = MAKE_SCRIPT_INT(x);
  scriptVar d = MAKE_SCRIPT_INT(y);
  scriptVar e = MAKE_SCRIPT_INT((int)p1);
  scriptVar f = MAKE_SCRIPT_INT((int)p2);
  scriptVar *params[6] = {&a, &b, &c, &d, &e, &f};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), sendaction_id, params));
}

int C_GuiObject::onAction(const wchar_t *action, const wchar_t *param, int x, int y, intptr_t p1, intptr_t p2, ScriptObject *source) 
{
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(action);
  scriptVar b = MAKE_SCRIPT_STRING(param);
  scriptVar c = MAKE_SCRIPT_INT(x);
  scriptVar d = MAKE_SCRIPT_INT(y);
  scriptVar e = MAKE_SCRIPT_INT((int)p1);
  scriptVar f = MAKE_SCRIPT_INT((int)p2);
  scriptVar g = MAKE_SCRIPT_OBJECT(source);
  scriptVar *params[7] = {&a, &b, &c, &d, &e, &f, &g};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), onaction_id, params));
}

int C_GuiObject::loaded=0;
int C_GuiObject::show_id=0;
int C_GuiObject::hide_id=0;
int C_GuiObject::isvisible_id=0;
int C_GuiObject::onsetvisible_id=0;
int C_GuiObject::setalpha_id=0;
int C_GuiObject::getalpha_id=0;
int C_GuiObject::onleftbuttonup_id=0;
int C_GuiObject::onleftbuttondown_id=0;
int C_GuiObject::onrightbuttonup_id=0;
int C_GuiObject::onrightbuttondown_id=0;
int C_GuiObject::onrightbuttondblclk_id=0;
int C_GuiObject::onleftbuttondblclk_id=0;
int C_GuiObject::onmousemove_id=0;
int C_GuiObject::onenterarea_id=0;
int C_GuiObject::onleavearea_id=0;
int C_GuiObject::setenabled_id=0;
int C_GuiObject::getenabled_id=0;
int C_GuiObject::onenable_id=0;
int C_GuiObject::resize_id=0;
int C_GuiObject::onresize_id=0;
int C_GuiObject::ismouseover_id=0;
int C_GuiObject::getleft_id=0;
int C_GuiObject::gettop_id=0;
int C_GuiObject::getwidth_id=0;
int C_GuiObject::getheight_id=0;
int C_GuiObject::settargetx_id=0;
int C_GuiObject::settargety_id=0;
int C_GuiObject::settargetw_id=0;
int C_GuiObject::settargeth_id=0;
int C_GuiObject::settargeta_id=0;
int C_GuiObject::settargetspeed_id=0;
int C_GuiObject::gototarget_id=0;
int C_GuiObject::ontargetreached_id=0;
int C_GuiObject::canceltarget_id=0;
int C_GuiObject::reversetarget_id=0;
int C_GuiObject::onstartup_id=0;
int C_GuiObject::isgoingtotarget_id=0;
int C_GuiObject::setxmlparam_id=0;
int C_GuiObject::getxmlparam_id=0;
int C_GuiObject::init_id=0;
int C_GuiObject::bringtofront_id=0;
int C_GuiObject::bringtoback_id=0;
int C_GuiObject::bringabove_id=0;
int C_GuiObject::bringbelow_id=0;
int C_GuiObject::getguix_id=0;
int C_GuiObject::getguiy_id=0;
int C_GuiObject::getguiw_id=0;
int C_GuiObject::getguih_id=0;
int C_GuiObject::getguirelatx_id=0;
int C_GuiObject::getguirelaty_id=0;
int C_GuiObject::getguirelatw_id=0;
int C_GuiObject::getguirelath_id=0;
int C_GuiObject::isactive_id=0;
int C_GuiObject::getparent_id=0;
int C_GuiObject::getparentlayout_id=0;
int C_GuiObject::gettopparent_id=0;
int C_GuiObject::runmodal_id=0;
int C_GuiObject::endmodal_id=0;
int C_GuiObject::findobject_id=0;
int C_GuiObject::findobjectxy_id=0;
int C_GuiObject::getname_id=0;
int C_GuiObject::clienttoscreenx_id=0;
int C_GuiObject::clienttoscreeny_id=0;
int C_GuiObject::clienttoscreenw_id=0;
int C_GuiObject::clienttoscreenh_id=0;
int C_GuiObject::screentoclientx_id=0;
int C_GuiObject::screentoclienty_id=0;
int C_GuiObject::screentoclientw_id=0;
int C_GuiObject::screentoclienth_id=0;
int C_GuiObject::getautowidth_id=0;
int C_GuiObject::getautoheight_id=0;
int C_GuiObject::setfocus_id=0;
int C_GuiObject::onchar_id=0;
int C_GuiObject::onaccelerator_id=0;
int C_GuiObject::ismouseoverrect_id=0;
int C_GuiObject::getinterface_id=0;
int C_GuiObject::onkeydown_id=0;
int C_GuiObject::onkeyup_id=0;
int C_GuiObject::ongetfocus_id=0;
int C_GuiObject::onkillfocus_id=0;
int C_GuiObject::sendaction_id=0;
int C_GuiObject::onaction_id=0;
