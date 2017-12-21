#pragma config(Sensor, in1,    armLift,        sensorPotentiometer)
#pragma config(Sensor, in2,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           leftFront,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           leftMid,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftBack,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightFront,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightMid,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightBack,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           leftLift,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightLift,    tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// RC CODE FOR THE NEW VEX ROBOT 11040A 6-MOTOR DRIVE


void leftDrive(double speed)
{
	motor[leftFront] = speed;
	motor[leftMid] = speed;
	motor[leftBack] = speed;
}


void rightDrive(short speed)
{
	motor[rightFront] = speed;
	motor[rightMid] = speed;
	motor[rightBack] = speed;
}


void armDrive(short speed)
{
	motor[leftLift] = speed;
	motor[rightlift] = speed;
}



<<<<<<< HEAD
=======

>>>>>>> 2b86622ec66d6a0c6289c0bd8004197a676cb691
task main()
{
	short leftSpeed;
	short rightSpeed;
<<<<<<< HEAD
	short armBaseCtrl;
	const short TIME_DEPLOY_CARRIER = 500;						//time to make a 90 deg angle for the mobile goal carrier
	const short LFIXED_ANGLE = 0;									//for the armFixed Pot
	const short HFIXED_ANGLE = 915;
	const short LLIFT_ANGLE = 1480;
	const short HLIFT_ANGLE = 2030;											//for the armLift Pot
	short grabberCtrl;
	short mobileGoalCtrl;
=======
	short armCtrl;
>>>>>>> 2b86622ec66d6a0c6289c0bd8004197a676cb691

	while(true)
	{
			/*				!!!		DRIVE CONTROLS		!!!
			*/
			//To control the left side using channel 3
			if (vexRT[Ch3] > -35 && vexRT[Ch3] < 35)
			{
				leftSpeed = 0;
			}
			else
			{
				leftSpeed = vexRT[Ch3];
			}

			//To control the right side using channel 2
			if (vexRT[Ch2] > -35 && vexRT[Ch2] < 35)
			{
				rightSpeed = 0;
			}
			else
			{
				rightSpeed = vexRT[Ch2];
			}

<<<<<<< HEAD
			/*				!!!		BASE ARM CONTROLS		!!!
=======
			leftDrive(leftSpeed);
			rightDrive(rightSpeed);


>>>>>>> 2b86622ec66d6a0c6289c0bd8004197a676cb691

			/*				!!!		ARM CONTROLS		!!!

			Pressing Button 6U should lift arm up
			Pressing Button 6D should drag arm down
			*/
<<<<<<< HEAD
			const short fixedSpeed = 80;
			const short liftSpeed = 80;
			if (vexRT[Btn6U] == 1) {
				motor[leftArmFix] = fixedSpeed;
				motor[rightArmFix] = fixedSpeed;
			}
			else if (vexRT[Btn6D] == 1) {
				motor[leftArmFix] = -fixedSpeed;
				motor[rightArmFix] = -fixedSpeed;
			}
			else {
				motor[leftArmFix] = 0;
				motor[rightArmFix] = 0;
			}

			if (vexRT[Btn5U] == 1) {
				motor[leftLift] = liftSpeed;
				motor[rightLift] = liftSpeed;
			}
			else if (vexRT[Btn5D] == 1) {
				motor[leftLift] = -liftSpeed;
				motor[rightLift] = -liftSpeed;
			}
			else {
				motor[leftLift] = 0;
				motor[rightLift] = 0;
			}
			/*armBaseCtrl = (vexRT[Btn6U] << 1) + vexRT[Btn6D];
			int armSpeed = 60;
			switch (armBaseCtrl)
			{
					case 1: //going down
							if (SensorValue[armLift] > LLIFT_ANGLE)
							{
								motor[leftArmFix] = -armSpeed;
								motor[rightArmFix] = -armSpeed;
								motor[leftLift] = -armSpeed;
								motor[rightLift] = -armSpeed;
							}
							else if (SensorValue[armFixed] > LFIXED_ANGLE)
							{
								motor[leftArmFix] = -armSpeed;
								motor[rightArmFix] = -armSpeed;
							}
							break;
					case 2: //going up
							if (SensorValue[armFixed] < HFIXED_ANGLE)
							{
								motor[leftArmFix] = armSpeed;
								motor[rightArmFix] = armSpeed;
								motor[leftLift] = armSpeed;
								motor[rightLift]= armSpeed;
							}
							else if (SensorValue[armLift] < HLIFT_ANGLE)
							{
								motor[leftLift] = armSpeed;
								motor[rightLift]= armSpeed;
							}
							break;
					default:
							motor[leftArmFix] = 0;
							motor[rightArmFix] = 0;
							break;
			}
			*/
			/*				!!!		GRABBER CONTROLS		!!!

			Pressing Button 8L should open the grabber
			Pressing Button 8R should close the grabber
			*/
			grabberCtrl = (vexRT[Btn8L] << 1) + vexRT[Btn8R];
			switch (grabberCtrl)
			{
					case 1:						//close
							motor[grabber] = -70;
							wait1Msec(250);
							motor[grabber] = 0;
							break;
					case 2:						//open
							motor[grabber] = 70;
							wait1Msec(250);
							motor[grabber] = 0;
							break;
					default:
							motor[grabber] = 0;
							break;
			 }



			/*				!!!		MOBILE GOAL CARRIER CONTROLS		!!!

					Pressing Button 8U should bring the mobile goal carrier up
					Pressing Button 8D should bring the mobile goal carrier down
			*/
			/*
			mobileGoalCtrl = (vexRT[Btn8D] << 1) + vexRT[Btn8U];
			switch (mobileGoalCtrl)
			{
					case 1:																//Bring carrier up
							motor[mobileGoal] = -127;
							wait1Msec(TIME_DEPLOY_CARRIER * 2);

							//to bring the armLifts down after setting the mobile goal in place
							motor[leftLift] = -127;
							motor[rightLift] = -127;
							wait1Msec(1000);
							motor[leftLift] = 0;
							motor[rightLift] = 0;

							break;
					case 2:																// Bring carrier down
							//to bring the armLifts up to prevent interferance with stacked yellow cones
							motor[leftLift] = 127;
							motor[rightLift] = 127;
							wait1Msec(1000);
							motor[leftLift] = 0;
							motor[rightLift] = 0;
							motor[mobileGoal] = 127;
							wait1Msec(TIME_DEPLOY_CARRIER);
							break;
					default:
							motor[mobileGoal] = 0;
							break;
			}*/
	}

=======
			armLiftCtrl = (vexRT[Btn6U] << 1) + vexRT[Btn6D];
			switch (armCtrl) {
				case 1:
					armDrive(127);
					break;

				case 2:
					armDrive(127)
					break;

				default:
					armDrive(0);
					break;

			}
>>>>>>> 2b86622ec66d6a0c6289c0bd8004197a676cb691
}
