unsigned char x,m,y,i,j,temp[3];

unsigned char color_wheel[16][3] = {
    {255, 0, 0},    // ��ɫ
    {255, 127, 0},  // ��ɫ
    {255, 255, 0},  // ��ɫ
    {127, 255, 0},  // ��ɫ
    {0, 255, 0},    // ��ɫ
    {0, 255, 127},  // ����ɫ
    {0, 255, 255},  // ����ɫ
    {0, 127, 255},  // ��ɫ
    {0, 0, 255},    // ����ɫ
    {127, 0, 255},  // ��ɫ
    {255, 0, 255},  // Ʒ��ɫ
    {255, 0, 127},  // ���ɫ
    {255, 0, 0},    // ��ɫ���ظ���Ϊ�˹���Ч����
    {255, 127, 0},  // ��ɫ���ظ���
    {255, 255, 0},  // ��ɫ���ظ���
    {127, 255, 0}   // ��ɫ���ظ���
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
            // ����ɫ���������ƶ�һλ
            for ( j = 0; j < 15; j++) 
         {
                color_wheel[j][0] = color_wheel[j + 1][0];
                color_wheel[j][1] = color_wheel[j + 1][1];
                color_wheel[j][2] = color_wheel[j + 1][2];
         }
            // �����һ��LED����ɫ����Ϊ����ĵ�һ����ɫ
            color_wheel[15][0] = color_wheel[0][0];
            color_wheel[15][1] = color_wheel[0][1];
            color_wheel[15][2] = color_wheel[0][2];
            
            color_wheel[0][0] = temp[0];
            color_wheel[0][1] = temp[1];
            color_wheel[0][2] = temp[2];

            sendLEDStrip(color_wheel);
            Delay1ms(100); // �ȴ�һ��ʱ�䣬���ƹ����ٶ�
       }// ִ�г�����ز���
  }