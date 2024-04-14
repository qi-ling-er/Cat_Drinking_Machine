# Cat_Drinking_Machine
这是一个嵌入式项目，所用环境为Keil5 MDK，项目名为猫猫饮水机，一共有两种模式，感应模式和定时模式
模式介绍
1.感应模式
    饮水机上电默认为感应模式。
    机器共四个红外传感器，均可触发自动出水，猫咪来到附近即可出发自动出水。

2.定时模式
    当按一下按键的时候，蜂鸣器会响一声，进入定时出水模式。
    在定时出水模式下，按一下按键，蜂鸣器会响两声，退出定时出水模式（回到感应模式）。
    在定时出水模式下，可自定义多长时间出水一次，及出水一次持续多长时间，修改具体位置见下图
    双击project.uvprojx文件，左侧选中
    ![image](https://github.com/qi-ling-er/Cat_Drinking_Machine/blob/main/Picture/%E5%AE%9A%E6%97%B6%E6%A8%A1%E5%BC%8F1.png)
    ![image](https://github.com/qi-ling-er/Cat_Drinking_Machine/blob/main/Picture/%E5%AE%9A%E6%97%B6%E6%A8%A1%E5%BC%8F2.png)

自定义引脚配置
每个模块可修改配置引脚，具体见
    按键（切换模式用的）
    ![image](https://github.com/qi-ling-er/Cat_Drinking_Machine/blob/main/Picture/%E6%8C%89%E9%94%AE1.png)
    红外传感器（可以不安四个，但修改程序需要一点点技术）
    ![image](https://github.com/qi-ling-er/Cat_Drinking_Machine/blob/main/Picture/%E7%BA%A2%E5%A4%961.png)
    ![image](https://github.com/qi-ling-er/Cat_Drinking_Machine/blob/main/Picture/%E7%BA%A2%E5%A4%962.png)
    ![image](https://github.com/qi-ling-er/Cat_Drinking_Machine/blob/main/Picture/%E7%BA%A2%E5%A4%963.png)
    ![image](https://github.com/qi-ling-er/Cat_Drinking_Machine/blob/main/Picture/%E7%BA%A2%E5%A4%964.png)
    蜂鸣器
    ![image](https://github.com/qi-ling-er/Cat_Drinking_Machine/blob/main/Picture/%E8%9C%82%E9%B8%A3%E5%99%A81.png)
    继电器
    ![image](https://github.com/qi-ling-er/Cat_Drinking_Machine/blob/main/Picture/%E7%BB%A7%E7%94%B5%E5%99%A81.png)
    
![定时模式1](https://github.com/qi-ling-er/Cat_Drinking_Machine/assets/124680954/903c5a46-784a-43a0-b97d-8c70930c0b90)
