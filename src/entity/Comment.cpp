
#include "Comment.h"
#include "Post.h"
#include "User.h"
#include "Tag.h"
#include "../auth/Token.h"

#include <Wt/Dbo/Impl.h>
#include <Wt/WWebWidget.h>

DBO_INSTANTIATE_TEMPLATES(Comment);

using std::string;
using std::cerr;

namespace 
{
    string& replace(string& text, const string& key, const string& replacement)
    {
        string::size_type pos = 0;

        while ((pos = text.find(key, pos)) != string::npos) {
            text.replace(pos, key.length(), replacement);
            pos += replacement.length();
        }

        return text;
    }
}

    /*string& replaceWithBr(string& text, const string& key, const string& replacement)
    {
      replace(text, "<br />" + key + "<br />", replacement);
      replace(text, "<br />" + key,            replacement);
      replace(text,            key + "<br />", replacement);
      replace(text,            key,            replacement);

      return text;
    }
  }


  void Comment::setText(const Wt::WString& src)
  {
    textSrc_ = src;

    string html = Wt::WWebWidget::escapeText(src, true).toUTF8();

    // Replace &lt;code&gt;...&lt/code&gt; with <pre>...</pre>
    // including leading/trailing <br />

    replaceWithBr(html, "&lt;code&gt;", "<pre>");
    replaceWithBr(html, "&lt;/code&gt;", "</pre>");

    // Replace empty line with <div class="vspace"></div>
    replace(html, "<br /><br />", "<div class=\"vspace\"></div>");

    textHtml_ = Wt::WString::fromUTF8(html);
  }
  */

    void Comment::setDeleted()
    {
        textHtml_ = Wt::WString::tr("comment-deleted");
    }


    void Comment::setText(const Wt::WString& src)
    {
        textSrc_ = src;

        std::string html = Wt::WWebWidget::escapeText(src, true).toUTF8();

        std::string::size_type b = 0;

        // Replace &lt;code&gt;...&lt/code&gt; with <pre>...</pre>
        // This is kind of very ad-hoc!

        while ((b = html.find("&lt;code&gt;", b)) != std::string::npos) {
            std::string::size_type e = html.find("&lt;/code&gt;", b);
            if (e == std::string::npos)
                break;
            else {
                if (b > 6 && html.substr(b - 6, 6) == "<br />") {
                    html.erase(b - 6, 6);
                    b -= 6;
                    e -= 6;
                }

                html.replace(b, 12, "<pre>");
                e -= 7;

                if (html.substr(b + 5, 6) == "<br />") {
                    html.erase(b + 5, 6);
                    e -= 6;
                }

                if (html.substr(e - 6, 6) == "<br />") {
                    html.erase(e - 6, 6);
                    e -= 6;
                }

                html.replace(e, 13, "</pre>");
                e += 6;

                if (e + 6 <= html.length() && html.substr(e, 6) == "<br />") {
                    html.erase(e, 6);
                    e -= 6;
                }

                b = e;
            }
        }

        // We would also want to replace <br /><br /> (empty line) with
        // <div class="vspace"></div>
        replace(html, "<br /><br />", "<div class=\"vspace\"></div>");

        textHtml_ = Wt::WString(html);
    }

