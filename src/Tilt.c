#include <pebble.h>
  

DictionaryIterator *iter;
Window *g_window;
Layer *divider_layer;
Layer *windowsLayer;

int textPos=0;

int drawnStockOnce=1;

void sendMsg();
  
void enterKey();

char *s1;
char *s2;
char *s3;

AppTimer *inputTimer = NULL;
void rebuildSidebar();
TextLayer *l1;
TextLayer *l2;
TextLayer *l3;
TextLayer *l4;
TextLayer *l5;
TextLayer *l6;
TextLayer *l7;
TextLayer *l8;
TextLayer *l9;
TextLayer *mainInput;

int xAxis;
int yAxis;
//\n
char input[100]="";
int firstKey=1;

int currentSetInt=1;
char *currentSet[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
char *set1[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
char *set2[] = {"j", "k", "l", "m", "n", "o", "p", "q", "r"};
char *set3[] = {"s", "t", "u", "v", "w", "x", "y", "z", "0"};
char *set4[] = {"1", "2", "3", "4", "5", "6", "7", "8","9"};
char *set5[] = {".", "?", ",", "/", " ", "(", ")", "+","-"};

int selected=-1;
int lastPressedButton=-1;

void setCurrentSet(int setNum){
  if(setNum==1){
      for(int x=0;x<9;x++){
        currentSet[x]=set1[x];
      }
  }
  if(setNum==2){
      for(int x=0;x<9;x++){
        currentSet[x]=set2[x];
      }  
  }
  if(setNum==3){
      for(int x=0;x<9;x++){
        currentSet[x]=set3[x];
      }  
  }
  if(setNum==4){
      for(int x=0;x<9;x++){
        currentSet[x]=set4[x];
      }  
  }
  if(setNum==5){
      for(int x=0;x<9;x++){
        currentSet[x]=set5[x];
      }  
  }
}
static void tap_handler(AccelAxisType axis, int32_t direction) {
        input[textPos] = 0;
        textPos--;
        text_layer_set_text(mainInput, input);
//         input[len-1] = '\0';
}

static void data_handler(AccelData *data, uint32_t num_samples) {
  xAxis= data[0].x;
  yAxis= data[0].y;
  if(xAxis >350 && yAxis >200){
    if(currentSetInt!=1){
      if(firstKey!=1){
        enterKey();
      }
      currentSetInt=1;
      setCurrentSet(1);
      rebuildSidebar();
    }
  }
  else if(xAxis>350 && yAxis<-200){
    if(currentSetInt!=2){
      if(firstKey!=1){
        enterKey();
      }
      currentSetInt=2;
      setCurrentSet(2);
      rebuildSidebar();
    }
  }
  else if(xAxis<-350 && yAxis<-200){
    if(currentSetInt!=3){
     if(firstKey!=1){
        enterKey();
      }
      currentSetInt=3;
      setCurrentSet(3);
      rebuildSidebar();
    }
  }
  else if(xAxis<-350 && yAxis>200){
    if(currentSetInt!=4){
      if(firstKey!=1){
        enterKey();
      }
      currentSetInt=4;
      setCurrentSet(4);
      rebuildSidebar();
    }
  }
  else if(xAxis<300 && xAxis > -300 && yAxis <100 && yAxis >-100){
    if(currentSetInt!=5){
      if(firstKey!=1){
        enterKey();
      }
      currentSetInt=5;
      setCurrentSet(5);
      rebuildSidebar();
    }
  }

}

//textLayer = layer to place text
//int y = y pos
//t = position in array
//h = highlight 1 or 0
void createLayer(TextLayer *var,int y, int t, int h){
  text_layer_destroy(var);
  var = text_layer_create(GRect(135, y, 16, 16));
      if(h==0){
        text_layer_set_background_color(var, GColorWhite);
        text_layer_set_text_color(var, GColorBlack);
      }
  else if (h==1){
    text_layer_set_background_color(var, GColorBlack);
        text_layer_set_text_color(var, GColorWhite);
  }
      layer_add_child(windowsLayer, text_layer_get_layer(var));
      text_layer_set_text(var, currentSet[t]);
}

void drawSelected(int x){
  if(selected==0){
    text_layer_destroy(l1);
    createLayer(l1,0,0,x);
  }
  else if(selected==1){
    text_layer_destroy(l2);
    createLayer(l2,16,1,x);
  }
  else if(selected==2){
    text_layer_destroy(l3);
    createLayer(l3,32,2,x);
  }
  else if(selected==3){
    text_layer_destroy(l4);
    createLayer(l4,53,3,x);
  }
  else if(selected==4){
    text_layer_destroy(l5);
    createLayer(l5,69,4,x);
  }
  else if(selected==5){
    text_layer_destroy(l6);
    createLayer(l6,85,5,x);
  }
  else if(selected==6){
    text_layer_destroy(l7);
    createLayer(l7,106,6,x);
  }
  else if(selected==7){
    text_layer_destroy(l8);
    createLayer(l8,122,7,x);
  }
  else if(selected==8){
    text_layer_destroy(l9);
    createLayer(l9,138,8,x);
  }
}
void enterKey(){
  textPos++;
      app_timer_cancel(inputTimer);    

//   append();
  strcat(input, currentSet[selected]);
  firstKey=1;
   drawSelected(0);
//   selected=-1;
  text_layer_set_text(mainInput, input);

}

void drawDividers(Layer *my_layer, GContext* ctx) {
  graphics_draw_rect(ctx,GRect(130,0,3,168));
  graphics_draw_rect(ctx,GRect(130,50,14,3));
  graphics_draw_rect(ctx,GRect(130,102,14,3));
}

void initialDraw(Window *window){
  mainInput = text_layer_create(GRect(10, 10, 100, 158));
  text_layer_set_background_color(mainInput, GColorWhite);
  text_layer_set_text_color(mainInput, GColorBlack);
  layer_add_child(window_get_root_layer(g_window), text_layer_get_layer(mainInput));

  createLayer(l1,0,0,0);
  createLayer(l2,16,1,0);
  createLayer(l3,32,2,0);
  createLayer(l4,53,3,0);
  createLayer(l5,69,4,0);
  createLayer(l6,85,5,0);
  createLayer(l7,106,6,0);
  createLayer(l8,122,7,0);
  createLayer(l9,138,8,0);
  divider_layer = layer_create(GRect(0,0,144,168));
  layer_set_update_proc(divider_layer, drawDividers);
  layer_add_child(window_get_root_layer(window), divider_layer);
}
void window_load(Window *window)
{
  initialDraw(window);
}

void rebuildSidebar(){
  text_layer_destroy(l1);
  createLayer(l1,0,0,0);
  text_layer_destroy(l2);
  createLayer(l2,16,1,0);
  text_layer_destroy(l3);
  createLayer(l3,32,2,0);
  text_layer_destroy(l4);
  text_layer_destroy(l5);
  text_layer_destroy(l6);
  text_layer_destroy(l7);
  text_layer_destroy(l8);
  text_layer_destroy(l9);
  createLayer(l4,53,3,0);
  createLayer(l5,69,4,0);
  createLayer(l6,85,5,0);
  createLayer(l7,106,6,0);
  createLayer(l8,122,7,0);
  createLayer(l9,138,8,0);
}

void window_unload(Window *window)
{
  text_layer_destroy(l1);
  text_layer_destroy(l2);
  text_layer_destroy(l3);
  text_layer_destroy(l4);
  text_layer_destroy(l5);
  text_layer_destroy(l6);
  text_layer_destroy(l7);
  text_layer_destroy(l8);
  text_layer_destroy(l9);
}



void up_single_click_handler(ClickRecognizerRef recognizer, void *context) {
  if(firstKey==1){
    selected=-1;
  }
  drawSelected(0);
  if(lastPressedButton!=0){
    app_timer_cancel(inputTimer);    
    if(firstKey!=1){
      enterKey();
    }
    selected=-1;
  }
  firstKey=0;
  selected++;
  
  if(selected>2){
    selected=0;
  }
  lastPressedButton=0;
  drawSelected(1);
  if(inputTimer){
    app_timer_cancel(inputTimer);
    inputTimer=app_timer_register(1000, enterKey, NULL);  
  }
  else{
    inputTimer=app_timer_register(1000, enterKey, NULL);  
  }
}
void select_single_click_handler(ClickRecognizerRef recognizer, void *context) {
  if(firstKey==1){
    selected=2;
  }
  drawSelected(0);
  if(lastPressedButton!=1){
    app_timer_cancel(inputTimer);
    if(firstKey!=1){
      enterKey();
    } 
    selected=2;
  }
  firstKey=0;  
  selected++;
  if(selected>5){
    selected=3;
  }
  lastPressedButton=1;
  drawSelected(1);
  if(inputTimer){
    app_timer_cancel(inputTimer);
    inputTimer=app_timer_register(1000, enterKey, NULL);  
  }
  else{
    inputTimer=app_timer_register(1000, enterKey, NULL);  
  }
}

void down_single_click_handler(ClickRecognizerRef recognizer, void *context) {
  if(firstKey==1){
    selected=5;
  }
    drawSelected(0);
  if(lastPressedButton!=2){
    app_timer_cancel(inputTimer);
    if(firstKey!=1){
      enterKey();
    }
    firstKey=0;
    selected=5;
  }
  selected++;
  if(selected>8){
    selected=6;
  }
  lastPressedButton=2;
  drawSelected(1);
  if(inputTimer){
    app_timer_cancel(inputTimer);
    inputTimer=app_timer_register(1000, enterKey, NULL);  
  }
  else{
    inputTimer=app_timer_register(1000, enterKey, NULL);  
  }
}
void process_tuple(Tuple *t){
  int key = t->key;
  char *v1 = t->value->cstring;
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Got key %d %s, value", key,v1);
  switch(key){
    case 1:
     s1=v1;
      APP_LOG(APP_LOG_LEVEL_INFO, "Got 'hello' message!");
      break;
    case 2:
       s2=v1;
      
      break;
      case 3:
      s3=v1;
      if(drawnStockOnce==1){
      strcat(s1,"\n");
      strcat(s1,"Last: ");
      strcat(s1,s2);
//       strcat(s1,"\n");
//       strcat(s1,"Change: ");
//       strcat(s1,s3);
//       strcat(s1,"%");
      text_layer_set_text(mainInput, s1);
      drawnStockOnce=0;
      }
    app_message_outbox_begin(&iter);
 
      if (iter == NULL) {
        APP_LOG(APP_LOG_LEVEL_ERROR, "Iter is null! Returning");
        return;
      }
 
      dict_write_cstring(iter, 1, input);
      dict_write_end(iter);
 
      app_message_outbox_send();
      break;
  }
}
 
void inbox(DictionaryIterator *iter, void *context){
  Tuple *t = dict_read_first(iter);
  if(t){
    process_tuple(t);
  }
  while(t != NULL){
    t = dict_read_next(iter);
    if(t){
      process_tuple(t);
    }
  }
}

void select_long_click_handler(){
//   strcat(xmsg, "a");
//   sendMsg();
  app_message_outbox_begin(&iter);
  dict_write_cstring(iter, 1, input);
      dict_write_end(iter);
        app_message_outbox_send();
}

void config_provider(Window *window) {
 // single click 
  window_single_click_subscribe(BUTTON_ID_UP, up_single_click_handler);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_single_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_single_click_handler);
//long click
  window_long_click_subscribe(BUTTON_ID_SELECT, 500, select_long_click_handler, NULL);
}

void sendMsg(){
  app_message_register_inbox_received(inbox);
  app_message_open(app_message_inbox_size_maximum(),app_message_outbox_size_maximum());

}


void init()
{
  
  uint32_t num_samples = 1;
accel_data_service_subscribe(num_samples, data_handler);
  accel_tap_service_subscribe(tap_handler);

    g_window = window_create();
    windowsLayer=window_get_root_layer(g_window);

    window_set_click_config_provider(g_window, (ClickConfigProvider) config_provider);
  window_set_window_handlers(g_window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
   
  sendMsg();


  window_stack_push(g_window, true);
  
}

void deinit()
{
  window_destroy(g_window);
}

int main(void)
{
  init();
  app_event_loop();
  deinit();
}