unsigned char x,m,y,i,j,temp[3];

unsigned char color_wheel[16][3] = {
    {255, 0, 0},    // 红色
    {255, 127, 0},  // 橙色
    {255, 255, 0},  // 黄色
    {127, 255, 0},  // 绿色
    {0, 255, 0},    // 青色
    {0, 255, 127},  // 薄荷色
    {0, 255, 255},  // 青绿色
    {0, 127, 255},  // 蓝色
    {0, 0, 255},    // 靛蓝色
    {127, 0, 255},  // 紫色
    {255, 0, 255},  // 品红色
    {255, 0, 127},  // 深红色
    {255, 0, 0},    // 红色（重复，为了滚动效果）
    {255, 127, 0},  // 橙色（重复）
    {255, 255, 0},  // 黄色（重复）
    {127, 255, 0}   // 绿色（重复）
};

void sendLEDStrip(unsigned char colors[16][3]) {
    unsigned char i;
    for (i = 0; i < 16; i++) {
        send_byte(colors[i][0], colors[i][1], colors[i][2]);
    }
}

 void Aya_Gen()
 {
    for (i = 0; i < 16; i++) 
     {
            // 将颜色数组向左移动一位
            for ( j = 0; j < 15; j++) 
         {
                color_wheel[j][0] = color_wheel[j + 1][0];
                color_wheel[j][1] = color_wheel[j + 1][1];
                color_wheel[j][2] = color_wheel[j + 1][2];
         }
            // 将最后一个LED的颜色设置为数组的第一个颜色
            color_wheel[15][0] = color_wheel[0][0];
            color_wheel[15][1] = color_wheel[0][1];
            color_wheel[15][2] = color_wheel[0][2];
            
            color_wheel[0][0] = temp[0];
            color_wheel[0][1] = temp[1];
            color_wheel[0][2] = temp[2];

            sendLEDStrip(color_wheel);
            Delay1ms(100); // 等待一段时间，控制滚动速度
       }// 执行长按相关操作
  }