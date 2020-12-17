#pragma once

namespace Tmpl8 {

    class Rocket;

    class ActionVisitor : public Visitor {
        public:
            ActionVisitor();
            void visit_rocket(Rocket* rocket) override;

            int test = 7;

        private:

        protected:
    };
}