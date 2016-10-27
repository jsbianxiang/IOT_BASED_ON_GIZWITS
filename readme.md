# 云端通讯数据格式
## 1. APP数据发送/接收区/设备数据发送/接收区

|通讯类型|事件序号|数据发送/接收方设备类型|数据发送/接收方MAC地址|命令|数据长度|数据|校验和|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|1 Byte|1 Byte|1 Byte|8 Byte|1 Byte|1 Byte|18 Byte|1 Byte|

## 2. 数据介绍
### (1). 通讯类型
|通讯代号|意义|
|:-:|:-:|
|0x00|结束此次通讯流程|
|0x01|APP请求与设备通讯|
|0x02|设备应答APP通讯|
|0x03|设备请求与APP通讯|
|0x04|APP应答设备通讯|
|0x05|网关请求与设备通讯|
|0x06|设备应答网关请求|
|0x07|设备请求与网关通讯|
|0x08|网关应答设备请求|
|0x09|校验码错误|

### (2). 事件序号
等待应答的事件序号应与应答的事件序号保持一致。

### (3). 设备类型
|设备类型|设备代码|
|:-:|:-:|
|网关|0x00|
|APP|0x00|
|灯|0x01|
|插座|0x02|
|窗帘|0x03|
|温湿度传感器|0x04|

备注：
若数据从APP发向设备，设备类型填写数据接收端的设备类型。
若数据从设备发向APP，设备类型填写数据发送方的设备类型。

### (4). 设备MAC地址
设备的MAC地址。

备注：
若数据从APP发向设备，设备MAC地址填写数据接收端的MAC地址。
若数据从设备发向APP，设备MAC地址填写数据发送方的MAC地址。

### (5). 命令
见数据点介绍。

### (6). 数据长度
数据长度表示数据的具体长度，不能超过最大数据长度。

### (7). 数据
见数据点介绍。

### (8).校验和
校验和的计算方式为把数据包从通讯类型为开始按字节求和得出的结果对256求余。

## 3. 数据点介绍(对应数据的内容)
### (1). 灯数据点介绍
|设备命令|设备命令介绍|权限|数据点|数据点大小|参数枚举|
|:-:|:-:|:-:|:-:|:-:|:-:|
|0x00|设备心跳|只读|NULL|NULL|NULL|
|0x01|灯的亮度|只读|1 Byte|NULL|0~255(0为关闭，255为开启)|
|0x02|灯的亮度|只写|1 Byte|NULL|0~255(0为关闭，255为开启)|
|0x03|倒计时设置|只读|详见定时器数据类型介绍|详见定时器数据类型介绍|详见定时器数据类型介绍|
|0x04|倒计时设置|只写|详见定时器数据类型介绍|详见定时器数据类型介绍|详见定时器数据类型介绍|
|0x05|定时开关设置|只读|详见定时器数据类型介绍|详见定时器数据类型介绍|详见定时器数据类型介绍|
|0x06|定时开关设置|只写|详见定时器数据类型介绍|详见定时器数据类型介绍|详见定时器数据类型介绍|

### (2).插座数据点
|设备命令|设备命令介绍|权限|数据点|数据点大小|参数枚举|
|:-:|:-:|:-:|:-:|:-:|:-:|
|0x00|设备心跳|只读|NULL|NULL|NULL|
|0x01|插座状态|只读|1 Byte|NULL|0~1(0为插座关闭，1为插座开启)|
|0x02|插座状态|只写|1 Byte|NULL|0~1(0为插座关闭，1为插座开启)|
|0x03|倒计时设置|只读|详见定时器数据类型介绍|详见定时器数据类型介绍|详见定时器数据类型介绍|
|0x04|倒计时设置|只写|详见定时器数据类型介绍|详见定时器数据类型介绍|详见定时器数据类型介绍|
|0x05|定时开关设置|只读|详见定时器数据类型介绍|详见定时器数据类型介绍|详见定时器数据类型介绍|
|0x06|定时开关设置|只写|详见定时器数据类型介绍|详见定时器数据类型介绍|详见定时器数据类型介绍|

### (3).窗帘数据点
|设备命令|设备命令介绍|权限|数据点|数据点大小|参数枚举|
|:-:|:-:|:-:|:-:|:-:|:-:|
|0x00|设备心跳|只读|NULL|NULL|NULL|
|0x01|窗帘状态|只读|窗帘的状态|1 Byte|0~1(0为窗帘关闭,1为窗帘开启)|
|0x02|窗帘状态|只写|窗帘的状态|1 Byte|0~1(0为窗帘关闭,1为窗帘开启)|
|0x03|倒计时设置|只读|详见定时器数据类型介绍|详见定时器数据类型介绍|详见定时器数据类型介绍|
|0x04|倒计时设置|只写|详见定时器数据类型介绍|详见定时器数据类型介绍|详见定时器数据类型介绍|
|0x05|定时开关设置|只读|详见定时器数据类型介绍|详见定时器数据类型介绍|详见定时器数据类型介绍|
|0x06|定时开关设置|只写|详见定时器数据类型介绍|详见定时器数据类型介绍|详见定时器数据类型介绍|
|0x07|APP通过该命令设置窗帘的工作模式|只读|智能工作模式开关|1 Byte|0~1|
|-|-|-|设定自动关闭窗帘的亮度|1 Byte|0~255|
|0x08|APP通过该命令设置窗帘的工作模式|只写|智能工作模式开关|1 Byte|0~1|
|-|-|-|设定自动关闭窗帘的亮度|1 Byte|0~255|

### (4).温湿度感应器数据点
|设备命令|设备命令介绍|权限|数据点|数据点大小|参数枚举|
|:-:|:-:|:-:|:-:|:-:|:-:|
|0x00|设备心跳|只读|NULL|NULL|NULL|
|0x01|APP通过该命令读取室内的温湿度|只读|室内的温度|1 Byte|0~100|
|-|-|-|室内的湿度|1 Byte|0~100|

## 4. 定时器数据类型介绍

|数据名称|成员|成员介绍|权限|占用内存|参数枚举|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|定时器工作模式|-|-|只读|1 Byte|TIMER_SLEEP_MODE = 0xB0(定时器休眠)|
|-|-|-|-|-|TIMER_SIGNAL_MODE = 0xB1(定时器单次运行模式)|
|-|-|-|-|-|TIMER_CUSTOM_MODE = 0xB2(定时器自定义运行模式)|
|自定义工作参数|-|-|读/写|1 Byte|配置定时器自定义运行模式的工作参数|
|-|status|自定义模式开启状态|读/写|Bit 0(占用此字节的第0位)|0~1|
|-|monday|周一工作状态|读/写|Bit 1(占用此字节的第1位)|0~1|
|-|tuesday|周二工作状态|读/写|Bit 2(占用此字节的第2位)|0~1|
|-|wednesday|周三工作状态|读/写|Bit 3(占用此字节的第3位)|0~1|
|-|thursday|周四工作状态|读/写|Bit 4(占用此字节的第4位)|0~1|
|-|friday|周五工作状态|读/写|Bit 5(占用此字节的第5位)|0~1|
|-|saturday|周六工作状态|读/写|Bit 6(占用此字节的第6位)|0~1|
|-|sunday|周日工作状态|读/写|Bit 7(占用此字节的第7位)|0~1|
|定时器工作时间|-|-|读/写|4 Byte|配置定时器的启动时间和停止时间|
|-|Start_Hour|启动时间-小时|读/写|1 Byte|0~23|
|-|Start_Minute|启动时间-分钟|读/写|1 Byte|0~59|
|-|Stop_Hour|停止时间-小时|读/写|1 Byte|0~23|
|-|Stop_Minute|停止时间-分钟|读/写|1 Byte|0~59|
|设备控制状态|-|-|读/写|2 Byte|配置定时器启动、停止时的设备状态|
|-|device_start_status|设备在定时器启动时的状态|读/写|1 Byte|根据设备而定|
|-|device_end_status|设备在定时器停止时的状态|读/写|1 Byte|根据设备而定|

## 5. 获取设备列表命令介绍
|控制命令|控制命令介绍|权限|数据点|数据点大小|参数枚举|
|:-:|:-:|:-:|:-:|:-:|:-:|
|0x00|设备列表变化|只读|NULL|NULL|NULL|
|0x01|APP通过该命令获取目前设备的数量|只读|设备的数量|1 Byte|1~255|
|0x02|APP通过该命令获取目前设备的信息|只读|设备编号(第X台设备)|1 Byte|1 ~ 255|
|-|-|-|设备类型|1 Byte|见设备类型|
|-|-|-|设备MAC地址|8 Byte|见设备MAC地址|
|0x03|设备信息发送完成标志|只读|-|-|-|
|0x04|读取设备列表失败|只读|-|-|-|

## 6. 通讯流程介绍
### (1). APP控制/读取设备数据流程介绍
APP向设备发送数据流程：

    APP ——> 云端 ——> WIFI模组 ——> 网关 ——> 设备

由上述流程可知APP发送的数据经过云端、WIFI模组、网关处理之后然后才到数据的，中间可能存在一些延迟，因此当APP发送写入/读取设备的数据命令数据经过网关时，网关会将数据发送给终端设备，发送成功的话会发送一个应答数据给云端表示设备正在处理此次事件，而设备解析完APP发送的命令数据之后会将设备信息通过设备上报的形式发送给云端(设备上报数据时的设备命令类型为只读命令)。

设备上报数据流程：

    设备 ——> 网关 ——> WIFI模组 ——> 云端 ——> APP
    
### (2). APP获取设备信息流程介绍
1. APP向网关设备请求获取在线设备数量。
2. 网关应答APP在线设备数量。
3. APP向网关发送需要获取设备信息的设备编号。
4. 网关回复APP请求的设备编号的设备信息(如果网关返回读取失败命令则APP应该重新执行获取设备信息流程)。
5. APP依次读完所有设备的设备信息。

备注：当设备列表有变化时，设备会向APP发送设备列表变化命令并等待APP读取设备信息。
