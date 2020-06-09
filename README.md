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
for the full tutorial on how to work with roboflow with your custom dataset please check the following link [Roboflow](https://blog.roboflow.ai/getting-started-with-roboflow/)

![alt text](https://i.imgur.com/WHFqYSJ.png)


### Folder structure 

 
 The software folder contains 2 items and 2 folders:
 1. Models contains the actual Faster-RCNN model being implemented 
 2. tensorflow-object-detection-faster-rcnn contains some .ipynb files that we can use to train the dataset on google colab 
 3. Faster-RCNN.ipynb this is the modified file that we will use for inference or training the Faster-RCNN model
 4. frozen_inference_graph.pb this is the file that will be outputed from the Faster-RCNN.ipynb after training the model using the dataset in the folder, This file will be used in inference mode
 
### Inference mode

1. Open Faster-RCNN.ipynb
2. Run this code snippet 

 ![1](https://user-images.githubusercontent.com/65522542/84104467-08b05e00-aa16-11ea-976e-d5e781555cd4.PNG)

3. Run this code snippet 
 * Number of evalutation steps isn't important when running the inference mode
 * If you run this code snippet and doing the training mode i suggest doing a small number of steps as a start ie. num_steps = 100 for example
 * The extracted frozen_graph.pb attached was done on 1000 steps because the number of the attached images isn't big enough so we don't run on the problem of overfitting
 * Make sure that the selected_model = 'faster_rcnn_inception_v2' to choose the Faster-RCNN model
  ![2](https://user-images.githubusercontent.com/65522542/84105102-9b053180-aa17-11ea-9251-2b4d324c9f34.PNG)
  
4. Run this code snippet

 ![3](https://user-images.githubusercontent.com/65522542/84105675-4cf12d80-aa19-11ea-89ef-ef27a78664e9.PNG)
 
5. This should be your folder after the last step
 
 ![4](https://user-images.githubusercontent.com/65522542/84105780-a22d3f00-aa19-11ea-9945-2ddf8220d7f4.PNG)
 
6. Run this code snippet 

 ![5](https://user-images.githubusercontent.com/65522542/84105992-3bf4ec00-aa1a-11ea-9b2d-a62e30e4f467.PNG)
 
7. This should be your folder after the last step ( Model folder should be added)

 ![6](https://user-images.githubusercontent.com/65522542/84106084-7ced0080-aa1a-11ea-9f56-36a2289f7ada.PNG)
 
8. Run this code snippet (may remove it )

 ![7](https://user-images.githubusercontent.com/65522542/84106815-66e03f80-aa1c-11ea-843a-99bb9fdedd77.PNG)
 
9. Create 2 directories named Test and Train as shown in the following screenshot

 ![8](https://user-images.githubusercontent.com/65522542/84107269-79a74400-aa1d-11ea-9fa2-77ac0926f9ac.PNG)

10. check the Dataset\Dataset1\VOC-test.v2.tfrecord folder where you can see the test and train directories 

 ![9](https://user-images.githubusercontent.com/65522542/84108625-e8d26780-aa20-11ea-9f8c-3ea720171bd8.PNG)
 
11. Add the content in the directories to the directories created in step 9 after this step it should look something like this

 ![10](https://user-images.githubusercontent.com/65522542/84108737-351da780-aa21-11ea-9a73-d88aafa2e72d.PNG)

12. we will work with the following code snippet in this step 

 ![11](https://user-images.githubusercontent.com/65522542/84108977-dad11680-aa21-11ea-912d-12b857139893.PNG)

 * In the first variable we should copy the path of the tfrecord file in the test directory we created in step 9 
 * In the second variable we should copy the path of the tfrecord file in the train directory we created in step 9 
 * In the third variable we should copy the path of the pbtxt file in the test directory we created in step 9 
 * Note: in order to copy the path simply right click on the file you want and then paste in the code snippet 
 * After the following steps this should be the shape of the code snippet 
 
 ![12](https://user-images.githubusercontent.com/65522542/84109415-e3761c80-aa22-11ea-95c4-19ff5b4408db.PNG)
 
13. Run the code snippet 
 
14. Run this code snippet 
 
 ![13](https://user-images.githubusercontent.com/65522542/84109596-5384a280-aa23-11ea-86d8-94ce168b589d.PNG)

15. Run these code snippets 

![14](https://user-images.githubusercontent.com/65522542/84109716-947cb700-aa23-11ea-8282-587f27fc34c0.PNG)

16. Create a new sub directory to the data directory named test after this step the folders should look like this 

![15](https://user-images.githubusercontent.com/65522542/84110141-972bdc00-aa24-11ea-9ebe-a40bf9962ea5.PNG)

17. Go to Dataset/Dataset2/subest_udacity_dataset where you can see the images we will use for testing these images are a subset of the udacity dataset 

18. upload the images you want to test in the inference mode to the test directory created in step 16 from the directory stated in step 17 your folders may look like this after uploading

![16](https://user-images.githubusercontent.com/65522542/84110730-b37c4880-aa25-11ea-8253-f9781ca5422f.PNG)

19. Upload the frozen_inference_graph.pb file found in software directory to the tensorflow-object-detection-faster-rcnn folder in google colabs your folders should look something like this( note the added pb file)

![17](https://user-images.githubusercontent.com/65522542/84110968-37363500-aa26-11ea-9e4c-0b2ff00454ff.PNG)

20. Now check this code snippet 

![18](https://user-images.githubusercontent.com/65522542/84111072-6a78c400-aa26-11ea-9beb-165124823c31.PNG)

 * Delete the frozen_inference_graph.pb in the following directory /content/models/research/pretrained_model/frozen_inference_graph.pb
 * Upload the new frozen_inference_graph.pb found in the software directory in github 

21. Run the code snippet 

22. add the following 2 lines at the start of this code snippet then run it 
!pip install tf-slim
num_classes = get_num_classes(label_map_pbtxt_fname)

![20](https://user-images.githubusercontent.com/65522542/84111271-deb36780-aa26-11ea-936b-c8e35d8c549b.PNG)

23.Run the remaining code snippets and enjoy the results!



### Results

![result](https://user-images.githubusercontent.com/65522542/84113393-c8a7a600-aa2a-11ea-8ba4-86d5915bfe2c.png)
![result2](https://user-images.githubusercontent.com/65522542/84113399-cb0a0000-aa2a-11ea-9ebe-f04284435362.png)
![result3](https://user-images.githubusercontent.com/65522542/84113407-ce04f080-aa2a-11ea-880a-11fa78042113.png)
![result4](https://user-images.githubusercontent.com/65522542/84113412-d0674a80-aa2a-11ea-9799-7ff276c8034d.png)
![result5](https://user-images.githubusercontent.com/65522542/84113381-c5acb580-aa2a-11ea-983f-d6a7fff82d9c.png)


























 
