//
// Created by Administrator on 2019/4/1.
//
#include "doe_criteria.h"
#include "doe_A2.h"

using namespace std;

#ifndef CPP_VERSION_MINCOHERE_H
#define CPP_VERSION_MINCOHERE_H

class MC: public Criteria{

    vector<vector<double> > CORR, tempCORR;
    double A;
    int M = 10000;
    Criteria *a2;
public:
    MC(vector<vector<double> > init,int nsamp_init,int nv_init, int nlevel_init): Criteria(nsamp_init, nv_init, nlevel_init) {
        a2 = new A2(init, nsamp_init, nv_init, nlevel_init);
        init_design(init);
        evaluate_criteria();
    }
    vector<vector<double> > get_design();
    void init_design(vector<vector<double> >);
    void update_design(vector<vector<double> >);
    void evaluate_criteria();
    double columnwise_exchange(int ncol,int ncp, vector<int> idx1,vector<int> idx2);
    vector<double> get_criteria_matrix();
};
#endif //CPP_VERSION_CRIT_H
