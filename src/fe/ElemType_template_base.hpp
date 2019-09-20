#ifndef __femus_fe_ElemType_templ_base_hpp__
#define __femus_fe_ElemType_templ_base_hpp__

#include <vector>
#include <string>
#include <boost/optional.hpp>


namespace femus

{
    
    
    
 template <class type, class type_mov>
    class elem_type_templ_base {
          
      public:      
                                   
     virtual void JacJacInv(const std::vector < std::vector < type_mov > > & vt,
                            const unsigned & ig,
                            std::vector < std::vector <type_mov> > & Jac,
                            std::vector < std::vector <type_mov> > & JacI,
                            type_mov & detJac,
                            const unsigned space_dimension) const = 0;

     virtual void compute_normal(const std::vector< std::vector< type_mov > > & Jac, std::vector< type_mov > & normal) const = 0;

     virtual void shape_funcs_current_elem(const unsigned & ig,
                                             const std::vector < std::vector <type_mov> > & JacI,
                                             std::vector < double > & phi, 
                                             std::vector < type >   & gradphi,
                                             boost::optional< std::vector < type > & > nablaphi,
                                             const unsigned space_dimension) const = 0;
                                             
    virtual void shape_funcs_volume_at_bdry_current_elem(const unsigned ig, 
                                                         const unsigned jface, 
                                                         const std::vector < std::vector <type_mov> > & JacI_qp, 
                                                         std::vector < double > & phi_vol_at_bdry,
                                                         std::vector < type >   & phi_x_vol_at_bdry, 
                                                         boost::optional< std::vector < type > & > nablaphi_vol_at_bdry,
                                                         const unsigned space_dimension) const = 0;
          
// run-time selection
      static elem_type_templ_base<type, type_mov> * build(const std::string geom_elem, /*dimension is contained in the Geometric Element*/
                                                              const std::string fe_fam,
                                                              const std::string order_gauss,
                                                              const unsigned space_dimension); 
    protected:
        
     virtual void jacobian(const std::vector < std::vector < type_mov > > & vt,
                           const unsigned & ig,
                           const std::vector < double ** > & dphidxi,
                           std::vector < std::vector <type_mov> > & Jac,
                           const unsigned space_dimension) const = 0;

     virtual void jac_jacT(const unsigned & ig,
                          const std::vector < std::vector <type_mov> > & Jac,
                          std::vector < std::vector <type_mov> > & JacJacT,
                          const unsigned space_dimension) const = 0;

     virtual void jac_jacT_inv(const unsigned & ig,
                          const std::vector < std::vector <type_mov> > & Jac,
                          std::vector < std::vector <type_mov> > & JacJacT,
                          const unsigned space_dimension) const {};

     virtual void area_transf(const unsigned & ig,
                          const std::vector < std::vector <type_mov> > & JacJacT,
                          type_mov & detJac,
                          const unsigned space_dimension) const {};

      };    

      
      







}

#endif
