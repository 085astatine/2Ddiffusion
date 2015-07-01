#ifndef FIELD_SOLVER_BOUNDARYBASE_H
#define FIELD_SOLVER_BOUNDARYBASE_H

#include <memory>
#include <vector>
#include <Eigen/Core>

namespace field{
namespace solver{
class BoundaryBase{
public:
    // constructor
    BoundaryBase(const std::shared_ptr<std::vector<double>>& x_pointer,
                 const std::shared_ptr<std::vector<double>>& y_pointer,
                 const std::shared_ptr<Eigen::MatrixXd>& value_pointer);
    // destructor
    virtual ~BoundaryBase(){};
    // 座標の境界値
    virtual double x_min(const std::ptrdiff_t& k) const = 0;
    virtual double x_max(const std::ptrdiff_t& k) const = 0;
    virtual double y_min(const std::ptrdiff_t& i) const = 0;
    virtual double y_max(const std::ptrdiff_t& i) const = 0;
    // 値の境界値
    virtual double value_x_min(const std::ptrdiff_t& k) const = 0;
    virtual double value_x_max(const std::ptrdiff_t& k) const = 0;
    virtual double value_y_min(const std::ptrdiff_t& i) const = 0;
    virtual double value_y_max(const std::ptrdiff_t& i) const = 0;
protected:
    const std::vector<double>& x() const;
    const std::vector<double>& y() const;
    const Eigen::MatrixXd& value() const;
private:
    // 各値へのpointer
    std::shared_ptr<std::vector<double>> x_ptr_;
    std::shared_ptr<std::vector<double>> y_ptr_;
    std::shared_ptr<Eigen::MatrixXd> value_ptr_;
};
}// end namespace solver
}// end namespace field
#endif// FIELD_SOLVER_BOUNDARYBASE_H
