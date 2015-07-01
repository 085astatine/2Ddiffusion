#include "./field_base.h"

namespace field{
// constructor
FieldBase::FieldBase(
            const std::shared_ptr<std::vector<double>>& xPointer,
            const std::shared_ptr<std::vector<double>>& yPointer,
            const std::shared_ptr<Eigen::MatrixXd>& zPointer)
      : x_ptr_(xPointer),
        y_ptr_(yPointer),
        z_ptr_(zPointer){}
// x座標列のpointerを返す
const std::shared_ptr<std::vector<double>>&
FieldBase::x_pointer() const{
    return x_ptr_;
}
// y座標列のpointerを返す
const std::shared_ptr<std::vector<double>>&
FieldBase::y_pointer() const{
    return y_ptr_;
}
// 値列のpointerを返す
const std::shared_ptr<Eigen::MatrixXd>&
FieldBase::z_pointer() const{
    return z_ptr_;
}
// 値を返す
const double& FieldBase::operator()(
            const std::ptrdiff_t& i,
            const std::ptrdiff_t& k) const{
    return z()(i, k);
}
// x座標列を返す
const std::vector<double>& FieldBase::x_list() const{
    return *x_pointer();
}
// y座標列を返す
const std::vector<double>& FieldBase::y_list() const{
    return *y_pointer();
}
// 値列を返す
const Eigen::MatrixXd& FieldBase::z() const{
    return *z_pointer();
}
// x座標値を返す
const double& FieldBase::x(const std::ptrdiff_t& i) const{
    return x_list()[i];
}
// y座標値を返す
const double& FieldBase::y(const std::ptrdiff_t& k) const{
    return y_list()[k];
}
}// end namespace field
