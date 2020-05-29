## Object Detection with MobileNetSSDv2 and Faster R-CNN and the TensorFlow Object Detection API

Thannks to https://github.com/Tony607/object_detection_demo for the intial demo!

## What is contained in this repo

* A tutorial to train and use MobileNetSSDv2 with the TensorFlow Object Detection API
* A tutorial to train and use Faster R-CNN with the TensorFlow Object Detection API 

## What you will learn (MobileNetSSDv2)

* How to load your custom image detection from Roboflow (here we use a public blood cell dataset with tfrecord)
* Download base MobileNetSSDv2 model
* Set up training environment
* Configure training pipeline and train the model
* Export the trained model's .pb inference graph
* Use the saved model for inference

## What you will learn (Faster R-CNN) 

* How to load your custom image data from Roboflow (here we use a public blood cell dataset with tfrecord)
* Download base pretrained Faster R-CNN model
* Set up training environment
* Configure training pipeline and train model
* Export the trained model's .pb inference graph
* Use the saved model for inference

## Resources available

* [This blog post for MobileNetSSDv2](https://blog.roboflow.ai/training-a-tensorflow-object-detection-model-with-a-custom-dataset/) walks through the tutorial
* [This blog post for Faster R-CNN](https://blog.roboflow.ai/training-a-tensorflow-faster-r-cnn-object-detection-model-on-your-own-dataset/) walks through the tutorial
* For the MobileNetSSDv2 model tutorial [![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/drive/1wTMIrJhYsQdq_u7ROOkf0Lu_fsX5Mu8a)
* For the Faster R-CNN  model tutorial [![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/drive/1U3fkRu6-hwjk7wWIpg-iylL2u5T9t7rr#scrollTo=yhzxsJb3dpWq)
* For reading purposes, for  MobileNetSSDv2, the notebook is saved here as Tutorial_Mobilenet.ipynb
* For reading purposes, for Faster R-CNN, the notebook is also saved here as Tutorial_Faster_RCNN.ipynb


## About Roboflow for Data Management

[Roboflow](https://roboflow.ai) makes managing, preprocessing, augmenting, and versioning datasets for computer vision seamless.
Developers reduce 50% of their code when using Roboflow's workflow, automate annotation quality assurance, save training time, and increase model reproducibility.

![alt text](https://i.imgur.com/WHFqYSJ.png)
