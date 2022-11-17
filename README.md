# Edit_Distance

The repository is used to release unofficial code for "Topolog aware  object-level semantic mapping towards more robust loop closure" for comparison. The programs of visible object detection and initial pose estimation are [VisualDet3D](https://github.com/Owen-Liuyuxuan/visualDet3D) and [VINS-Fusion](https://github.com/HKUST-Aerial-Robotics/VINS-Fusion) respectively.

## Setup

1.1 Ubuntu and ROS

Ubuntu 64-bit 18.04. ROS Melodic.

1.2 [VisualDet3D](https://github.com/Owen-Liuyuxuan/visualDet3D)

- environment setup

```bash
pip3 install -r requirement.txt
```

- config and path setup

Please modify the path and parameters in **visualDet3D/config*.py** files.

- stereo image as input training

```bash
./launchers/det_precompute.sh config/$CONFIG_FILE.py train
./launcher/train.sh  config/$CONFIG_FILE.py 0 $experiment_name
```

- stereo image as input testing

```bash
./launchers/det_precompute.sh config/$CONFIG_FILE.py test
./launchers/eval.sh config/$CONFIG_FILE.py 0 visualDet3D/workdirs/Stereo3D/checkpoint/Stereo3D_latest.pth test
```

- the evaluate results

the object detected results files should be stored in **sequences/xx**. VINS-Fusion can read the results.

1.3 [VINS-Fusion](https://github.com/HKUST-Aerial-Robotics/VINS-Fusion)

- environment setup

ceres solver: follow [Ceres Installation](http://ceres-solver.org/installation.html)

- KITTI Example

```bash
 roslaunch vins vins_rviz.launch
  rosrun vins kitti_odom_test ~/catkin_ws/src/VINS-Fusion/config/kitti_odom/kitti_config00-02.yaml YOUR_DATASET_FOLDER/sequences/00/
```

1.4 Edit_distance

With the object detection results and pose estimation results, you can test your own loop detection and store its results as two files, such as **graph1.txt, graph2.txt**. To compute the graphs edit distance, you can run:

```bash
./ED path_to_graph1/graph1.txt path_to_graph2/graph2.txt
```

The executable program will output the minimum edit distance between graph1 and graph2.



## Related Paper:

if you think the code is useful, please cite the following papers.

```bash
@ARTICLE{9327478,
  author={Y. {Liu} and Y. {Yuan} and M. {Liu}},
  journal={IEEE Robotics and Automation Letters}, 
  title={Ground-aware Monocular 3D Object Detection for Autonomous Driving}, 
  year={2021},
  doi={10.1109/LRA.2021.3052442}}
  
@article{qin2019fusion,
  author={Tong Qin and Jie Pan and Shaozu Cao and Shaojie Shen},
  title={A General Optimization-based Framework for Local Odometry Estimation with Multiple Sensors},
  journal={ArXiv},
  year={2019},
  volume={abs/1901.03638}}
  
@ARTICLE{lin_topology_2021,  
  author={Lin, Shiqi and Wang, Jikai and Xu, Meng and Zhao, Hao and Chen, Zonghai},  
  journal={IEEE Robotics and Automation Letters},   
  title={Topology Aware Object-Level Semantic Mapping Towards More Robust Loop Closure},   
  year={2021}
  doi={10.1109/LRA.2021.3097242}}
```

