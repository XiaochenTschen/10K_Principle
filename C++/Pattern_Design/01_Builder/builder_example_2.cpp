#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

struct HtmlBuilder;

struct HtmlElement {
    string name;
    string text;
    vector<HtmlElement> elements;
    static unique_ptr<HtmlBuilder> build(const string& root_name) {
        return make_unique<HtmlBuilder>(root_name);
    }

    string str(int indent = 0) const {
        // pretty-print the content
        ostringstream oss;
        string i(indent, ' ');  // 生成缩进空格

        oss << i << "<" << name << ">" << endl;

        if (!text.empty()) {
            oss << string(indent + 2, ' ') << text << endl;
        }

        for (const auto& e : elements) {
            oss << e.str(indent + 2);  // 子元素增加缩进
        }

        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }

protected: // hiden all constructors
    HtmlElement() {}
    HtmlElement(const string& name, const string& text) 
        : name(name), text(text) {}
    friend struct HtmlBuilder;
};

struct HtmlBuilder {
    HtmlElement root;

    HtmlBuilder(const string& root_name) {
        root.name = root_name;
    }

    HtmlBuilder& add_child(const string& child_name, const string& child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    }

    operator HtmlElement&() { return root; };

    string str() const {
        return root.str();
    }
};

int main() {
    HtmlElement e = HtmlElement::build("ul")
        ->add_child("li", "hello")
        .add_child("li", "world");
    cout << e.str();

    return 0;
}