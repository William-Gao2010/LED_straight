# LED灯带控制程序

## 项目简介
这是一个基于STC8G系列单片机的LED灯带控制程序，用于实现多种动态显示效果。程序通过控制WS2812B或其他类似的LED灯带，展示颜色滚动、随机颜色显示等功能。程序分为多个模式，用户可以通过按键切换不同的显示模式。

## 程序功能
1. **颜色滚动模式**：
   - 灯带上的颜色按照预定义的颜色轮（彩虹色）滚动显示。
   - 颜色轮包括红色、橙色、黄色、绿色、青色、蓝色、紫色等。
2. **随机颜色模式**：
   - 随机生成颜色，并在灯带上显示。
   - 每次显示的颜色和位置都是随机的。
3. **ADC颜色模式**：
   - 通过ADC采集模拟信号，将采集到的值转换为颜色值，并在灯带上显示。
   - 支持多个ADC通道，分别控制RGB颜色。
4. **按键切换模式**：
   - 用户可以通过按键切换不同的显示模式。

## 硬件需求
- STC8G系列单片机开发板
- LED灯带（WS2812B或其他类似灯带）
- 按键模块
- 电源（5V）
- 连接线

## 硬件连接
1. 将LED灯带的控制引脚连接到单片机的P3.7（或其他指定引脚）。
2. 将按键的一端连接到单片机的P3.3，另一端连接到GND。
3. 确保LED灯带的电源和地线连接正确。
4. 如果使用ADC功能，将模拟信号源连接到单片机的ADC引脚（如P1.0、P1.1、P1.6）。

## 使用方法
1. **编译程序**：
   - 使用STC-ISP软件将程序编译并烧录到单片机中。
2. **运行程序**：
   - 接通电源后，灯带将按照默认模式显示颜色。
   - 按下按键，可以切换到不同的显示模式。
3. **修改显示效果**：
   - 修改`color_wheel`数组中的颜色值，可以自定义颜色轮。
   - 修改`mode_A`、`mode_B`和`mode_C`函数中的逻辑，可以实现新的显示模式。

Email:17156310913ghj@gmail.com
