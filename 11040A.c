#pragma config(Sensor, in1,    armLift,        sensorPotentiometer)
#pragma config(Sensor, in2,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           leftFront,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           leftMid,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftBack,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightFront,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightMid,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightBack,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           leftLift,    tmotorVex393_MC29, openLoop, reversed)
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



task main()
{
	short leftSpeed;
	short rightSpeed;
	short armLiftCtrl;

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

			leftDrive(leftSpeed);
			rightDrive(rightSpeed);



			/*				!!!		BASE ARM CONTROLS		!!!

			Pressing Button 6U should lift entire arm up
			Pressing Button 6D should drag entire arm down
			*/
			armBaseCtrl = (vexRT[Btn6U] << 1) + vexRT[Btn6D];


}
