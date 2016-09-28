/*
 * arTracker.cpp
 *
 *  Created on: Aug 24, 2016
 *      Author: ubuntu
 */

#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <iostream>
#include <tf/tf.h>
#include <tf/transform_datatypes.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <ar_track_alvar_msgs/AlvarMarker.h>


/* Where I left off:
 * Try changing .launch
 * find out topic of bebop driver
 * Calibrate camera using opencv node
 * Run tests between each step, getting large amounts of measurements quickly
 *  
 */



void poseCb(ar_track_alvar_msgs::AlvarMarkers msg) { //no control over loop rate and which tags are detected, inneficient 

	for (ar_track_alvar_msgs::AlvarMarker tag : msg.markers) {
		if (tag.id != 0)
			std::cout << "ID: " << tag.id << " x: " << tag.pose.pose.position.x << std::endl;
	}

/*
	}catch (tf::TransformException& ex){
		std::cout <<"transformexception" <<std::endl;
	    ROS_ERROR("%s",ex.what());
	    std::cout << "transformexception" <<std::endl;
	    return;
	}catch (std::out_of_range& ex) {
		std::cout <<"arrayoutofdbounds" <<std::endl;
		ROS_ERROR("%s", ex.what());
		std::cout <<"arrayoutofdbounds" <<std::endl;
		return;
	}
*/
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "arTracker");
	ros::NodeHandle n;

	tf::TransformListener listener;
	ros::Rate loop_rate(1);
	 while (ros::ok()){
	    tf::StampedTransform transformBase;
	    tf::StampedTransform transformCamera;
	    try{
	      listener.lookupTransform( "/ar_marker_30","/base_link",ros::Time(0), transformBase);
	      listener.lookupTransform( "/ar_marker_30","/camera_base_link",ros::Time(0), transformCamera);
	    }
	    catch (tf::TransformException& ex){
	      ROS_ERROR("%s",ex.what());;
	      ros::Duration(1.0).sleep();
	      continue;
	    }
	    std::cout << "Base x: "<< transformBase.getOrigin().x() << std::endl;
	    std::cout << "Base y: "<< transformBase.getOrigin().y() << std::endl;
	    std::cout << "Base z: "<< transformBase.getOrigin().z() << std::endl;
	    
	    std::cout << "Camera y: "<< transformBase.getOrigin().x() << std::endl;
	    std::cout << "Camera y: "<< transformBase.getOrigin().y() << std::endl;
	    std::cout << "Camera y: "<< transformBase.getOrigin().z() << std::endl;
	    
	    loop_rate.sleep();

	 }

	return 0;
}

