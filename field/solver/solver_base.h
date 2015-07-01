#ifndef FIELD_SOLVER_SOLVERBASE_H
#define FIELD_SOLVER_SOLVERBASE_H

#include <memory>
#include <vector>
#include <Eigen/Core>

namespace field{
namespace solver{
// forward declaration
class BoundaryBase;

class SolverBase{
public:
    // constructor
    SolverBase(const std::shared_ptr<std::vector<double>>& x_pointer,
               const std::shared_ptr<std::vector<double>>& y_pointer,
               const std::shared_ptr<Eigen::MatrixXd>& value_pointer,
               const std::shared_ptr<BoundaryBase>& boundary_pointer);
    // destructor
    virtual ~SolverBase(){}
    // 実行
    virtual void solve(const double& time) = 0;
    // x,y座標値列
    const std::vector<double>& x() const;
    const std::vector<double>& y() const;
    // 値列
    const Eigen::MatrixXd value() const;
    // 境界設定
    const BoundaryBase& boundary() const;
private:
    // 値列のpointer
    std::shared_ptr<std::vector<double>> x_ptr_;
    std::shared_ptr<std::vector<double>> y_ptr_;
    std::shared_ptr<Eigen::MatrixXd> value_ptr_;
    // 境界設定
    std::shared_ptr<BoundaryBase> boundary_ptr_;
};
}// end namespace solver
}// end namespace field
#endif// FIELD_SOLVER_SOLVERBASE_H
