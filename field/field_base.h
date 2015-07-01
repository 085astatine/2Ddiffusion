#ifndef FIELD_FIELDBASE_H
#define FIELD_FIELDBASE_H

#include <memory>
#include <vector>
#include <Eigen/Core>

namespace field{
class FieldBase{
public:
    // constructor
    FieldBase(const std::shared_ptr<std::vector<double>>& x_pointer,
              const std::shared_ptr<std::vector<double>>& y_pointer,
              const std::shared_ptr<Eigen::MatrixXd>& z_pointer);
    // destructor
    virtual ~FieldBase(){}
    // 値を返す
    const double& operator()(
                const std::ptrdiff_t& i,
                const std::ptrdiff_t& k) const;
    // 各値へのpointerを返す
    const std::shared_ptr<std::vector<double>>& x_pointer() const;
    const std::shared_ptr<std::vector<double>>& y_pointer() const;
    const std::shared_ptr<Eigen::MatrixXd>& z_pointer() const;
    // x, y座標列を返す
    const std::vector<double>& x_list() const;
    const std::vector<double>& y_list() const;
    // 値列を返す
    const Eigen::MatrixXd& z() const;
    // x, y座標値を返す
    const double& x(const std::ptrdiff_t& i) const;
    const double& y(const std::ptrdiff_t& k) const;
private:
    // x,y座標列 pointer
    std::shared_ptr<std::vector<double>> x_ptr_;
    std::shared_ptr<std::vector<double>> y_ptr_;
    // 値列
    std::shared_ptr<Eigen::MatrixXd> z_ptr_;
};
}// end namespace field
#endif// FIELD_FIELDBASE_H
