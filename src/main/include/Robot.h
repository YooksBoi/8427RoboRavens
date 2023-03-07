// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>
#include "ctre/Phoenix.h"
#include <frc/smartdashboard/SendableChooser.h>

#include <frc/XboxController.h>

#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/PWMVictorSPX.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/PneumaticHub.h>
#include <frc/Timer.h>
#include <frc/TimedRobot.h>
/////////////////////////////////////////////
#include <frc/PneumaticsControlModule.h>
#include <frc/DoubleSolenoid.h>
#include <frc/Compressor.h>
/////////////////////////////////////////////

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

  frc::XboxController xboxController{0};
  frc::Timer timer;

  frc::Compressor pcmCompressor{0, frc::PneumaticsModuleType::CTREPCM};
  frc::DoubleSolenoid solenoid{0, frc::PneumaticsModuleType::CTREPCM,1,2};
  

  WPI_VictorSPX backLeft{1};
  WPI_VictorSPX backRight{2};
  WPI_VictorSPX frontLeft{3};
  WPI_VictorSPX frontRight{4};
  
  frc::MotorControllerGroup right{frontRight, backRight};
  frc::MotorControllerGroup left{frontLeft, backLeft};

  frc::DifferentialDrive drivetrain{left, right};
 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
