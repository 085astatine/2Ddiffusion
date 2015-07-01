#include "./solver_base.h"
#include "./boundary_base.h"

namespace field{
namespace solver{
// constructor
SolverBase::SolverBase(
            const std::shared_ptr<std::vector<double>>& x_pointer,
            const std::shared_ptr<std::vector<double>>& y_pointer,
            const std::shared_ptr<Eigen::MatrixXd>& value_pointer,
            const std::shared_ptr<BoundaryBase>& boundary_pointer)
      : x_ptr_(x_pointer),
        y_ptr_(y_pointer),
        value_ptr_(value_pointer),
        boundary_ptr_(boundary_pointer){}
// x座標値列
const std::vector<double>& SolverBase::x() const{
    return *x_ptr_;
}
// y座標値列
const std::vector<double>& SolverBase::y() const{
    return *y_ptr_;
}
// 値列
const Eigen::MatrixXd SolverBase::value() const{
    return *value_ptr_;
}
// 境界設定
const BoundaryBase& SolverBase::boundary() const{
    return *boundary_ptr_;
}
}// end namespace solver
}// end namespace field
