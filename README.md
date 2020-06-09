# Hardware-FasterRCNN
This is the implementation for a hardware Faster-RCNN neural network architecture used in object detection in autonomous cars we will divide this project into 2 parts
The first part is the software implementation of our Faster-RCNN neural network
The second part of the code is the hardware implementation of the backbone network of the Faster-RCNN (VGG-16) to fasten the simulation 
The hardware implementation will be only used in inference mode and we will use the software implementation to get the correct weights we will 
use in the hardware part


## Software implementation

### Introduction


* We will be simulating the Faster-RCNN architecture using google colabs as this will fasten the training using google servers
* we will use a unique custom dataset which is a subset of the VOCtrainval_11-May-2012 that contains objects that is present on the road normally 
* This data set is found in the dataset folder where it is divided into training and testing groups











 
