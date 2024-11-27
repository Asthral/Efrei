<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
                xmlns:php="http://php.net/xsl" version="1.0">
    <xsl:template match="/">
        <!-- Récupère la liste des fonctions désactivées -->
        <xsl:value-of select="php:function('ini_get', 'disable_functions')" />
    </xsl:template>
</xsl:stylesheet>
