#!/usr/bin/env roseus
(load "package://hrpsys_ros_bridge_tutorials/euslisp/samplerobot-interface.l")

;; (ros::roseus "node_name")
;; (ros::advertise "/topic" geometry_msgs::PointStamped 1)
;; (ros::subscribe "/topic" geometry_msgs::PointStamped #'method-cb)
;; (do-until-key (ros::spin-once))

(defun sr-init
  ()
  (samplerobot-init)
  (setq *robot* *sr*)
  (objects (list *robot*))
  (send *robot* :reset-manip-pose)
  (send *robot* :fix-leg-to-coords (make-coords))
  (send *robot* :torso-waist-p :joint-angle 20)
  ;; (send *robot* :init-pose)
  (send *irtviewer* :draw-objects)
  )

(defun ri-init
  ()
  (send *ri* :angle-vector (send *robot* :angle-vector) 5000)
  (send *ri* :wait-interpolation)
  (send *ri* :start-auto-balancer)
  (send *ri* :wait-interpolation)
  (send *ri* :start-st)
  (send *ri* :wait-interpolation)
  (send *ri* :go-pos 0 0 0)
  )

(defun demo
  ()
  (sr-init)
  ;; (ri-init)
  )
