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
* This data set is found in the dataset folder where it is divided into 2 folders one which contains the images and the annotation files(XML format) and the 
other folder contains the tfrecord format that will be used in training ( explained later )


### About Roboflow for Data Management

[Roboflow](https://roboflow.ai) makes managing, preprocessing, augmenting, and versioning datasets for computer vision seamless.
Developers reduce 50% of their code when using Roboflow's workflow, automate annotation quality assurance, save training time, and increase model reproducibility.

This website is used to change from one format to another to the annotation files and this will be used to generate the formats we will need in training 
in case you need to train on your custom dataset ( note the dataset attached in the dataset folder already has the correct format )

![alt text](https://i.imgur.com/WHFqYSJ.png)


### Folder structure 

 
 The software folder contains 2 items and 2 folders:
 1. Models contains the actual Faster-RCNN model being implemented 
 2. tensorflow-object-detection-faster-rcnn contains some .ipynb files that we can use to train the dataset on google colab 
 3. Faster-RCNN.ipynb this is the modified file that we will use for inference or training the Faster-RCNN model
 4. frozen_inference_graph.pb this is the file that will be outputed from the Faster-RCNN.ipynb after training the model that will be used in inference mode
 
 













 
