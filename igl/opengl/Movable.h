#pragma once
#include <Eigen/core>
#include <Eigen/Geometry>
#include <Eigen/dense>


class Movable
{
public:
	Movable();
	Movable(const Movable& mov);
	Eigen::Matrix4f MakeTransScale();
	Eigen::Matrix4d MakeTransd();
	Eigen::Matrix4d MakeTransScaled();
	void MyTranslate(Eigen::Vector3d amt, bool preRotation);
	void SetCenterOfRotation(Eigen::Vector3d amt);
	void TranslateInSystem(Eigen::Matrix3d rot,Eigen::Vector3d amt);
	void MyRotate(Eigen::Vector3d rotAxis, double angle);
	void MyRotate(const Eigen::Quaterniond& rot);
	void RotateInSystem(Eigen::Matrix3d& Mat, Eigen::Quaterniond  rot);
	Eigen::Vector3d GetTranslation();
	Eigen::Quaterniond GetRotationQuaterniond();
	void RotateInSystem(Eigen::Vector3d rotAxis, double angle);
	void MyRotate(const Eigen::Matrix3d &rot);
	void MyScale(Eigen::Vector3d amt);
	void RotateInSystem(Eigen::Matrix4d Mat, Eigen::Vector3d rotAxis, double angle);
	Eigen::Vector3d getCenterOfRotation();
	Eigen::Matrix3d GetRotation() const{ return Tout.rotation().matrix(); }
	void SetTranslation(Eigen::Vector3d position);
	void resetTranslation();

	virtual ~Movable() {}
private:
	Eigen::Affine3d Tout,Tin;
};

