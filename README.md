# HybridOS

HybridOS is a totally new open source operating system designed for smart IoT devices
and cloud computing environment.

HybridOS tries to provide the developers with more possibilities than just a
traditional operating system for a stand-alone hardware environment.

HybridOS not only runs on smart IoT devices to support application development
on devices, but also provides programming interfaces for the cloud and the clients.
It tries to give the developers a new complete software stack and protocol stack
from devices to the cloud and the clients.

## Table of Contents

- [Why We Design a New OS for IoT?](#why-we-design-a-new-os-for-iot)
- [Technical Terminologies](#technical-terminologies)
- [Goals of HybridOS](#goals-of-hybridos)
- [Design Documents and Specifications](#design-documents-and-specifications)
- [Organization of Source Code](#organization-of-source-code)
- [Current Status](#current-status)
- [Copying](#copying)

## Why We Design a New OS for IoT?

At present, when we want to develop a consumer IoT (Internet of Things) device,
we have to build a software team which has five engineers at least due to
the complex software stack and protocol stack of IoT computing environment:

* At least one firmware engineer who writes programs in C/C++ for
the IoT device, which generally runs a RTOS or Linux.
* At least one server engineer who writes programs in Java/PHP/Python
for the cloud services.
* At least one front-end engineer who writes webpages in
JavaScript/CSS/HTML5 for webpages.
* At least two client-end engineers who write apps in Java,
Objective C, or Swift for smart phones, which run Android or iOS.

In addition, for some devices which are used for business, we need one
or two engineers to write desktop apps in C/C++ for Windows, macOS,
or Linux.

Obviously, the development cost of an IoT device is much higher
than a traditional embedded device. We need a new operating system to
simplify the software and protocol stack of IoT applications,
reduce the development cost, and improve the productivity.

Not only that, the popular cloud computing services we can get from
AWS, Ali, or Huawei are not dedicated for IoT applications. We have
to develop some cloud services by ourselves to implement some features
for our IoT devices. Moreover, the security of an IoT service
is being seriously challenged.

For example, with the development of IoT technologies, we can now use our
own smart phone to remotely control the home air conditioner or view the
home camera in real time.  We can even use the smart phone to remotely open
our home door from the office. However, have you ever thought about the issue:
how your smart lock knows that the received door open command is sent by you?
Or, conversely, is the real-time monitoring screen that you see on your smart
phone generated by your own camera?

The reality is that any cracker who breaks into the cloud can easily control
all IoT devices connected to the cloud remotely, including your smart door locks or
cameras. The current IoT products, like traditional Internet applications, have not
improved much in terms of security. The scenes that we can often see from spy war
movies can still be easily performed in reality.

This is because most IoT developers are not security experts, and they often
downplay the security challenges of the IoT system or choose a bad solution
to implement a security policy.

Some ideas from the blockchain technology may change this. The decentralized
design of the blockchain provides another way to enhance the security of IoT.
HybridOS will try to utilize the some parts of blockchain technology and
the mature and successful practice from the industry to improve the security
of IoT.

We see HybridOS as an operating system running on the network. We are committed
to freeing IoT developers from various protocol stacks and complex software
stacks. At the same time, HybridOS hides the security implementation details
in order that the developers can focus on their applications.

## Technical Terminologies

* Device: The IoT device; For HybridOS, the device here refers to a smart
  device that has direct access to the Internet and with or without a display.
* Device App: An app runs on a device, with or without GUI.
* Client: A desktop computer, a smart phone, or a tablet.
* Client App: An app runs on a client.
* Node: The IoT node; For HybridOS, the node here refers to a constrained IoT
  device in a constrained network.

## Goals of HybridOS

### A specialized software stack for IoT

HybridOS provides a new software stack for IoT applications:

* A new implementation for common server, such as MQTT, WebSocket, HTTP,
  CoAP, and streaming servers. HybridOS provides a different
  architecture for the implementation of the servers: any HybridOS app or
  service can register and work as a real service provider or a request provider
  of the servers.

* A new and universal app framework for IoT devices and client apps.
  The developers can write device app and client apps for Linux, Windows, macOS,
  Android, and iOS operating systems by using a set of extended HTML5 tags
  and CSS 3. On low-end IoT devices, you use C++ as the script language of HVML,
  while you use JavaScript on high-end IoT devices and/or clients.

Finally, the application programming languages of HybridOS will be reduced to two:
JavaScript or C/C++ for apps. As a result, the development cost of
an IoT application will be reduced greatly by using HybridOS.

### IoT-dedicated cloud computing services and security implementation

HybridOS integrates some cloud computing services which are dedicated to IoT,
such as a distributed MQTT server, identity authentication mechanism,
and some basic services, such as firmware and app upgrade.

HybridOS will introduce the serverless technology for the IoT cloud
computing. In this way, the developer can easily integrate the existed
cloud services by writing a simple script in Python.

In the future, HybridOS will try to provide a blockchain-based IoT security
service. HybridOS will provide an enhanced MQTT implementation for
communication between things and an identity authentication mechanism
based on blockchain technology/idea.

### Rich connectivities

On the device side, HybridOS integrates a standard peripheral and task
management interface based on hBus (an enhanced edition of OpenWRT's uBus),
such as networking management, sensor (like GPS and gravity accelerometer)
management, and USB interface management. hBus exchanges data among apps
and services in JSON, which is friendly for any programming language.

HybridOS will provide a variety of connectivity options for the IoT devices,
including 4G/LTE, NB-IoT, Wi-Fi, Bluetooth, ZigBee, NFC, RFID, USB, Ethernet,
RS232, and so on.

The device-side system of HybridOS is based on the Linux kernel, making
full use of the Linux kernel ecosystem, reducing the difficulty of developing
various drivers and the difficulty of supporting various protocol stacks,
thus reducing development cost.

## Design Documents and Specifications

[HybridOS Architecture] gives you a whole picture of HybridOS.

For all documents, please refer to [HybridOS Documents].

## Organization of Source Code

### Main Repository

The main repository of HybridOS is <https://github.com/FMSoftCN/hybridos>.
It mainly contains building scripts, tools, documents, and samples for
HybridOS:

    `
    |-- docs/           # The design documents for HybridOS.
    |-- device-side/    # The source for device side.
    |-- server-side/    # The source for server side.
    |-- client-side/    # The source for client side.

### Other Repositories

We use some popular open source software as the common infrastructure
of HybridOS. However, we have done a lot of adjustments and
optimizations for some of the key software. We call the changed versions
of the software as derivatives for HybridOS and maintain them
through the following public repositories:

- App Framework
   + hiWebKit: the HybridOS derivative of [WebKit]: N/a.

- Graphics Stack:
   + hiCairo: the HybridOS derivative of [Cairo]:
<https://github.com/FMSoftCN/hicairo>
   + MiniGUI: the windowing system for HybridOS:
<https://github.com/VincentWei/minigui>

- System Servers: N/a.

- System Daemons:
   + hiBus: the HybridOS derivative of uBus:
<https://github.com/FMSoftCN/hibus>
   + hiLogged: the HybridOS logging service: N/a.
   + hiSecd (the HybridOS security service): N/a.


## Current Status

- Nov. 2019:  
Initial release of hiCairo.
- Nov. 2018:  
Initiate this project and organize specifications and design documents.

## Copying

Copyright (C) 2018 \~ 2019 [Beijing FMSoft Technologies Co., Ltd.]

- For device side and client side, all new components use LGPLv3.
- For server side, all new components uses AGPLv3.
- For documents, GPLv3 applies.

If a component of HybridOS is a derivative of an existing
open source software, we generally continue to use the original license.

Also note that HybridOS integrates many mature open source software,
such as SQLite, FreeType, V8 JavaScript engine, and so on. For the
copyright owners and licenses for these software, please refer to
the README or LICENSE files contained in the source tarballs.

---

[Cairo]: https://www.cairographics.org/

[HybridOS Documents]: docs/README.md
[HybridOS Architecture]: docs/specs/HybridOS-Architecture.md
[HybridOS Code and Development Convention]: docs/specs/HybridOS-Code-and-Development-Convention.md

[Beijing FMSoft Technologies Co., Ltd.]: https://www.fmsoft.cn
[FMSoft Technologies]: https://www.fmsoft.cn
[HybridOS Official Site]: https://hybrid.fmsoft.cn

[MiniGUI]: http:/www.minigui.com
[WebKit]: https://webkit.org
[HTML 5.3]: https://www.w3.org/TR/html53/

