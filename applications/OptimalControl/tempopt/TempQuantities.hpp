#ifndef __femus_tempopt_TempQuantities_hpp__
#define __femus_tempopt_TempQuantities_hpp__

#include <iostream>
#include <cstdlib>

#include "Typedefs.hpp"
#include "Quantity.hpp"

#include "OptLoop.hpp"
#include "TimeLoop.hpp"


using namespace femus;

class Temperature : public Quantity {

  public:
   Temperature(std::string name_in, QuantityMap& qtymap_in, uint dim_in, uint FEord_in);
  ~Temperature(){};
  void Function_txyz(const double t, const double* xp,double* temp) const;  
  void bc_flag_txyz(const double t, const double* xp, std::vector<int> & flag) const;
  void initialize_xyz(const double* xp, std::vector<double> & value) const;
 
};

//===============
class TempLift : public Quantity {

  public:
   TempLift(std::string name_in, QuantityMap& qtymap_in, uint dim_in, uint FEord_in);
  ~TempLift(){};
  void Function_txyz(const double t, const double* xp,double* temp) const;  
  void bc_flag_txyz(const double t, const double* xp, std::vector<int> & flag) const;
  void initialize_xyz(const double* xp, std::vector<double> & value) const;
  
};


//===============
class TempAdj : public Quantity {

  public:
   TempAdj(std::string name_in, QuantityMap& qtymap_in, uint dim_in, uint FEord_in);
  ~TempAdj(){};
  void Function_txyz(const double t, const double* xp,double* temp) const;  
  void bc_flag_txyz(const double t, const double* xp, std::vector<int> & flag) const;
  void initialize_xyz(const double* xp, std::vector<double> & value) const;
  

};

//===============
class TempDes : public Quantity {

  public:
   TempDes(std::string name_in, QuantityMap& qtymap_in, uint dim_in, uint FEord_in);
  ~TempDes(){};
  void Function_txyz(const double t, const double* xp,double* temp) const;  
  

};



class Pressure : public Quantity {

  public:
   Pressure(std::string name_in, QuantityMap& qtymap_in, uint dim_in, uint FEord_in);
  ~Pressure(){};
  
  void Function_txyz(const double t, const double* xp,double* temp) const;  
  void bc_flag_txyz(const double t, const double* xp, std::vector<int> & flag) const;
  void initialize_xyz(const double* xp, std::vector<double> & value) const;

 

};


class VelocityX : public Quantity {

  public:
  VelocityX(std::string name_in, QuantityMap& qtymap_in);
    VelocityX(std::string name_in, QuantityMap& qtymap_in, uint dim_in, uint FEord_in);

  ~VelocityX(){};

  void Function_txyz(const double t, const double* xp,double* temp) const;  
  void bc_flag_txyz(const double t, const double* xp, std::vector<int> & flag) const;
  void initialize_xyz(const double* xp, std::vector<double> & value) const;

};

class VelocityY : public Quantity {

  public:
  VelocityY(std::string name_in, QuantityMap& qtymap_in);
    VelocityY(std::string name_in, QuantityMap& qtymap_in, uint dim_in, uint FEord_in);

  ~VelocityY(){};

  void Function_txyz(const double t, const double* xp,double* temp) const;  
  void bc_flag_txyz(const double t, const double* xp, std::vector<int> & flag) const;
  void initialize_xyz(const double* xp, std::vector<double> & value) const;

};

#endif