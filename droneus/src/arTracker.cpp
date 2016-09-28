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
#include <vector>


/* Where I left off:
 * Try changing .launch
 *
 */



void poseCb(ar_track_alvar_msgs::AlvarMarkers msg) {

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

	//ros::Subscriber pose_sub = n.subscribe("ar_pose_marker", 1000, poseCb);


	//ros::spin();

	tf::TransformListener listener;
	ros::Rate loop_rate(1);
	 while (ros::ok()){
	    tf::StampedTransform transformBase;
	    tf::StampedTransform transformCamera;
	    try{
	      listener.lookupTransform( "/ar_marker_30","/base_link",ros::Time(0), transformBase);
	    }
	    catch (tf::TransformException& ex){
	      ROS_ERROR("%s",ex.what());;
	      ros::Duration(1.0).sleep();
	      continue;
	    }
	    std::cout << "Base x: "<< transformBase.getOrigin().x() << std::endl;
	    std::cout << "Base y: "<< transformBase.getOrigin().y() << std::endl;
	    loop_rate.sleep();

	 }

	return 0;
}

