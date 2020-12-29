#include "precomp.h"

namespace Tmpl8 {

    KDTree::KDTree(){

    }

    KDTree::KDTree(Tank* item){
        this->item = item;
    }

    void KDTree::add(Tank* item, int depth){

        if(depth % 2 == 0){
           if(this->item != NULL){
                if(item->get_position().y < this->item->get_position().y){
                    if(this->left != NULL){
                        this->left->add(item, depth + 1);
                    } else {
                        this->left = new KDTree(item);
                    }
                } else {
                    if(this->right != NULL){
                        this->right->add(item, depth + 1);
                    } else {
                        this->right = new KDTree(item);
                    }
                }
            } else {
                this->item = item;
            }
        } else {
            if(this->item != NULL){
                if(item->get_position().x < this->item->get_position().x){
                    if(this->left != NULL){
                        this->left->add(item, depth + 1);
                    } else {
                        this->left = new KDTree(item);
                    }
                } else {
                    if(this->right != NULL){
                        this->right->add(item, depth + 1);
                    } else {
                        this->right = new KDTree(item);
                    }
                }
            } else {
                this->item = item;
            }
        }
    }

}