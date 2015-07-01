#include "./boundary_base.h"

namespace field{
namespace solver{
// constructor
BoundaryBase::BoundaryBase(
            const std::shared_ptr<std::vector<double>>& x_pointer,
            const std::shared_ptr<std::vector<double>>& y_pointer,
            const std::shared_ptr<Eigen::MatrixXd>& value_pointer)
      : x_ptr_(x_pointer),
        y_ptr_(y_pointer),
        value_ptr_(value_pointer){}
// 座標値列
const std::vector<double>& BoundaryBase::x() const{
    return *x_ptr_;
}
// 座標値列
const std::vector<double>& BoundaryBase::y() const{
    return *y_ptr_;
}
// 値列
const Eigen::MatrixXd& BoundaryBase::value() const{
    return *value_ptr_;
}
}// end namespace solver
}// end namespace field
