/* This file was generated by Maki Compiler, do not edit manually */

#include <precomp.h>

#include <api/script/objcontroller.h>
#include "h_text.h"

H_Text::H_Text(ScriptObject *o) : H_GuiObject(o) {
  inited = 0;
  obj = NULL;
  H_hook(o);
}

H_Text::H_Text() {
  inited = 0;
  obj = NULL;
}

void H_Text::H_hook(ScriptObject *o) {
  ASSERT(!inited);
  ScriptObjectController *controller = o->vcpu_getController();
  obj = controller->cast(o, textGuid);
  if (obj != o && obj != NULL)
    o = obj;
  else
    obj = NULL;

  addMonitorObject(o, &textGuid);

  int iter = WASABI_API_APP->app_getInitCount();
  if (!loaded || loaded != iter) {
    ontextchanged_id= WASABI_API_MAKI->maki_addDlfRef(o->vcpu_getController(), L"onTextChanged", this);
    loaded = 1;
  }
  inited=1;
}

H_Text::~H_Text() {
  if (!inited) return;
  WASABI_API_MAKI->maki_remDlfRef(this);
}

ScriptObject *H_Text::getHookedObject() {
  if (obj != NULL) return obj;
  return H_TEXT_PARENT::getHookedObject();
}

int H_Text::eventCallback(ScriptObject *object, int dlfid, scriptVar **params, int nparams) {
  if (object != getHookedObject()) return 0;
  if (H_TEXT_PARENT::eventCallback(object, dlfid, params, nparams)) return 1;
  if (dlfid == ontextchanged_id) { hook_onTextChanged(GET_SCRIPT_STRING(*params[0])); return 1; }
  return 0;
}

int H_Text::ontextchanged_id=0;
int H_Text::loaded=0;
