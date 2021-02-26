//https://wiki.openoffice.org/wiki/Writer/API/Overview

#ifndef UNOWRITER_H
#define UNOWRITER_H

#include <sal/main.h>
#include <osl/file.hxx>
#include <cppuhelper/bootstrap.hxx>
#include <com/sun/star/bridge/XUnoUrlResolver.hpp>

#include <com/sun/star/frame/Desktop.hpp>
#include <com/sun/star/frame/XComponentLoader.hpp>
#include <com/sun/star/lang/XMultiComponentFactory.hpp>

#include <com/sun/star/text/XTextDocument.hpp>
#include <com/sun/star/text/XText.hpp>

#include <com/sun/star/text/XTextTable.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>

#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/style/XStyle.hpp>
#include <com/sun/star/style/BreakType.hpp>
#include <com/sun/star/style/ParagraphAdjust.hpp>

#include <com/sun/star/awt/FontWeight.hpp>


using namespace com::sun::star::uno;
using namespace com::sun::star::lang;
using namespace com::sun::star::frame;

using namespace com::sun::star::text;

using namespace com::sun::star::table;

using namespace com::sun::star::beans;
using namespace com::sun::star::style;

using namespace com::sun::star::awt;


using ::rtl::OUString;
using ::rtl::OUStringToOString;

class UNOWriter
{
public:
    UNOWriter();
    ~UNOWriter();

    void createNewCompLO();
    void openExisCompLO(std::string pathToFile);
    void writeTextDoc(std::string text, int pos=0);
    void createDocTable(int row, int count);
    void setTableData(std::string position, double data);
    void setTableData(std::string position, std::string data);
    void chooseStyle(std::string styleName);
    void chooseStyle(std::string position, std::string styleName);
    void chooseFontName(std::string fontName);
    void chooseFontSize(float fontSize);
    void chooseFontWeight(float fontWeight);

    void chooseAlign(int align);

    void breakPage();

private:
    Reference< XDesktop2 > xComponentLoader;
    Reference< XComponent > xComponent;
    Reference< XTextDocument > xDocument;
    Reference< XText > xText;
    Reference< XTextRange > xTextRange;
    Reference< XTextCursor > xCursor;
    Reference< XMultiServiceFactory > oDocMSF;
    Reference< XTextTable > xDocTable;
};



#endif // UNOWRITER_H
