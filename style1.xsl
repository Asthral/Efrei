<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
                xmlns:php="http://php.net/xsl" version="1.0">

    <xsl:template match="/">
        <!-- Ouvre le répertoire courant -->
        <xsl:variable name="dir" select="php:function('opendir', './')" />

        <!-- Lit les fichiers dans le répertoire -->
        <xsl:for-each select="php:function('readdir', $dir)">
            <xsl:value-of select="." />
            <xsl:text>&#10;</xsl:text>
        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>
